//
// Created by CBerl139 on 28/04/2025.
//

#include "LauncherApp.h"
#include "Magnum/GL/DefaultFramebuffer.h"
#include <imgui.h>
#include <iostream>

LauncherApp::LauncherApp(const Arguments& args):
        GlfwApplication{args, Configuration{}.setTitle("Launcher").setSize({400,200})}
{
    _imgui = ImGuiIntegration::Context{
            Vector2{windowSize()} / dpiScaling(),
            windowSize(),
            GL::defaultFramebuffer.viewport().size()
    };

    onlineClient = OnlineClient("localhost", 5009);

    _timeline.start();
}

void LauncherApp::drawEvent() {
    Magnum::GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

    _timeline.nextFrame();
    _imgui.newFrame();

    if(ImGui::GetIO().WantTextInput && !isTextInputActive())
        startTextInput();
    else if(!ImGui::GetIO().WantTextInput && isTextInputActive())
        stopTextInput();

    ImGui::StyleColorsDark();

    // Center window
    ImVec2 size{300,100};
    ImVec2 pos{(ImGui::GetIO().DisplaySize.x - size.x)/2,
               (ImGui::GetIO().DisplaySize.y - size.y)/2};
    ImGui::SetNextWindowPos(pos, ImGuiCond_Always);
    ImGui::SetNextWindowSize(size, ImGuiCond_Always);

    ImGui::Begin("Login", nullptr,
                 ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove);

    //ImGui::InputText("Username", _usernameBuffer, sizeof(_usernameBuffer));
    //if(ImGui::Button("Submit")) {
    //    std::cout << "Entered username: " << _usernameBuffer << std::endl;
    //    // here you'd call handleLogin(), once this part works
    //}

    if (_state == State::Offline) {
        ImGui::InputText("Username", _usernameBuffer, sizeof(_usernameBuffer));
        //ImGui::InputText("Password", _passwordBuffer, sizeof(_passwordBuffer), ImGuiInputTextFlags_Password);

        if (ImGui::Button("Login")) {
            _username = _usernameBuffer;
            //_password = _passwordBuffer;
            std::cout << "Entered username: " << _usernameBuffer << std::endl;
            handleLogin();
        }
    } else if (_state == State::LoggedIn) {
        ImGui::Text("Logged in.");
        if (ImGui::Button("Find Match")) {
            handleMatchmaking();
        }
    } else if (_state == State::Matchmaking) {
        ImGui::Text("Matchmaking...");
        waitForSessionID();
    } else if (_state == State::ReadyToLaunch) {
        ImGui::Text("Match found!");
        if (ImGui::Button("Launch Game")) {
            launchGame();
        }
    } else if (_state == State::Error) {
        ImGui::Text("Error: %s", _errorMessage.c_str());
        if (ImGui::Button("Retry")) {
            _state = State::Offline;
        }
    }

    ImGui::End();

    _imgui.drawFrame();
    _imgui.updateApplicationCursor(*this);

    swapBuffers();
    redraw();
}

void LauncherApp::viewportEvent(ViewportEvent& event) {
    GL::defaultFramebuffer.setViewport({{}, event.framebufferSize()});
    _imgui.relayout({Vector2{event.windowSize()} / event.dpiScaling()},
                    event.windowSize(), event.framebufferSize());
}


void LauncherApp::pointerPressEvent(PointerEvent& event) {
    if(_imgui.handlePointerPressEvent(event)) { event.setAccepted(); return; }
}

void LauncherApp::pointerReleaseEvent(PointerEvent& event) {
    if(_imgui.handlePointerReleaseEvent(event)) { event.setAccepted(); return; }
}

void LauncherApp::keyPressEvent(KeyEvent& event) {
    if(_imgui.handleKeyPressEvent(event)) { event.setAccepted(); return; }
}

void LauncherApp::keyReleaseEvent(KeyEvent& event) {
    if(_imgui.handleKeyReleaseEvent(event)) { event.setAccepted(); return; }
}

void LauncherApp::textInputEvent(TextInputEvent& event) {
    if(_imgui.handleTextInputEvent(event)) { event.setAccepted(); return; }
}


void LauncherApp::handleLogin() {
    bool loginStatus = onlineClient.login(_username);
    _state = loginStatus ? State::LoggedIn : State::Error;


}

void LauncherApp::handleMatchmaking() {
    bool mmStatus = onlineClient.startMatchmaking();
    _state = mmStatus ? State::Matchmaking : State::Error;
}

void LauncherApp::waitForSessionID() {
    bool sessionStatus = onlineClient.pollSession(sessionID);
    onlineClient.isFindingMatch = false;    // not necessary but you never know
    _state = sessionStatus ? State::ReadyToLaunch : State::Error;
}

void LauncherApp::launchGame() {
    // Path to your built client executable
    const char* clientCmd =
#ifdef _WIN32
            "MagnumClient.exe";
#else
    "./MagnumClient";
#endif

#ifdef _WIN32
    // STARTUPINFO/PROCESS_INFORMATION to launch detached
    STARTUPINFOA si{};
    PROCESS_INFORMATION pi{};
    si.cb = sizeof(si);
    // CREATE_NEW_PROCESS_GROUP | DETACHED_PROCESS makes it independent
    if(CreateProcessA(
            clientCmd,      // lpApplicationName
            nullptr,        // lpCommandLine
            nullptr,        // lpProcessAttributes
            nullptr,        // lpThreadAttributes
            FALSE,          // bInheritHandles
            CREATE_NEW_PROCESS_GROUP|DETACHED_PROCESS,
            nullptr,        // lpEnvironment
            nullptr,        // lpCurrentDirectory
            &si, &pi)) {
        // We don't need these handles
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    } else {
        std::cerr << "Failed to launch client (" << GetLastError() << ")\n";
    }
#else
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork");
    } else if(pid == 0) {
        // child
        execl(clientCmd, clientCmd, nullptr);
        // if exec fails:
        perror("execl");
        _exit(EXIT_FAILURE);
    } else {
        // optionally: don't wait on child (detached)
        signal(SIGCHLD, SIG_IGN);
    }
#endif

    // Now exit the launcher immediately
    std::exit(0);
}

// Entry point
MAGNUM_APPLICATION_MAIN(LauncherApp)
