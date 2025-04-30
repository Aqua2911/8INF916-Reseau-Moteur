# GAME LAUNCHER
add_executable(LauncherApp
        LauncherApp.cpp
        LauncherApp.h
        ${PROJECT_SOURCE_DIR}/src/client/OnlineClient.cpp
        ${PROJECT_SOURCE_DIR}/src/client/OnlineClient.h
)

target_link_libraries(LauncherApp PRIVATE
        Magnum::GlfwApplication
        MagnumIntegration::ImGui
        Magnum::GL
)

if (WIN32)
  target_link_libraries(LauncherApp PRIVATE ws2_32)
endif()


target_include_directories(LauncherApp PRIVATE
        ${PROJECT_SOURCE_DIR}/externals/cpp-httplib
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)
