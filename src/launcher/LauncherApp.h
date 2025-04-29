//
// Created by CBerl139 on 28/04/2025.
//

#ifndef MAGNUMSERVER_LAUNCHERAPP_H
#define MAGNUMSERVER_LAUNCHERAPP_H

#pragma once

#include "Magnum/Platform/GlfwApplication.h"
#include "Magnum/ImGuiIntegration/Context.hpp"
#include <string>
#include "../client/OnlineClient.h"

using namespace Magnum;
using namespace Magnum::Platform;

class LauncherApp : public GlfwApplication {
public:
    explicit LauncherApp(const Arguments& arguments);

private:
    // Core
    void drawEvent() override;
    void viewportEvent(ViewportEvent& event) override;

    // Forward all input to ImGui
    void keyPressEvent(KeyEvent& event) override;
    void keyReleaseEvent(KeyEvent& event) override;
    void textInputEvent(TextInputEvent& event) override;
    void pointerPressEvent(PointerEvent& event) override;
    void pointerReleaseEvent(PointerEvent& event) override;

    // ImGui + state
    ImGuiIntegration::Context _imgui{NoCreate};
    Timeline _timeline;

    void handleLogin();
    void handleMatchmaking();
    void launchGame();
    void waitForSessionID();

    enum class State {
        Offline,
        LoggedIn,
        Matchmaking,
        ReadyToLaunch,
        Error
    } _state = State::Offline;

    std::string _username;
    std::string _password;
    std::string _token;
    std::string _matchInfo;
    std::string _errorMessage;

    char _usernameBuffer[256]{};
    char _passwordBuffer[256]{};

    OnlineClient onlineClient;
    std::string sessionID;
};


#endif //MAGNUMSERVER_LAUNCHERAPP_H
