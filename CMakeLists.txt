cmake_minimum_required(VERSION 3.10)
project(MagnumServer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})


set(USE_TLS  OFF CACHE BOOL "Disable TLS support in IXWebSocket" FORCE)
set(USE_ZLIB OFF CACHE BOOL "Disable Zlib support in IXWebSocket" FORCE)

##add_subdirectory(externals/IXWebSocket)

add_subdirectory(externals)
include_directories(${PROJECT_SOURCE_DIR}/externals/enet6/include)

find_package(Magnum REQUIRED
        GL
        GlfwApplication
        Primitives
        Shaders
        Trade
        MeshTools
        SceneGraph)

find_package(MagnumIntegration REQUIRED ImGui Bullet)
find_package(Bullet REQUIRED Dynamics)

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

# =======================
# Main GUI Application
# =======================
add_executable(MagnumServer
        src/server_main.cpp
        src/Serializable/InstanceData.cpp
        src/Serializable/Serializable.cpp
        src/BulletApp.cpp
        src/Serializable/ObjectData.cpp
        src/Serializable/ColoredDrawable.cpp
        src/client/OnlineClient.cpp
        src/client/OnlineClient.h
)

target_include_directories(MagnumServer PRIVATE
        $<TARGET_PROPERTY:enet,INTERFACE_INCLUDE_DIRECTORIES>
        inc
        ${PROJECT_SOURCE_DIR}/externals/enet6/include
        ${PROJECT_SOURCE_DIR}/externals/cpp-httplib
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)

set_property(TARGET MagnumServer PROPERTY CXX_STANDARD 20)

target_link_libraries(MagnumServer PRIVATE
        Magnum::Application
        Magnum::GL
        Magnum::Magnum
        Magnum::MeshTools
        Magnum::Primitives
        Magnum::SceneGraph
        Magnum::Shaders
        Magnum::Trade
        MagnumIntegration::Bullet
        MagnumIntegration::ImGui
        Bullet::Dynamics
        BulletDynamics
        BulletCollision
        LinearMath
        Bullet3Common
        enet
)

# ==========================
# Define the client application
# ==========================
add_executable(MagnumClient
        src/client_main.cpp
        src/Serializable/InstanceData.cpp
        src/Serializable/Serializable.cpp
        src/BulletApp.cpp
        src/Serializable/ObjectData.cpp
        src/Serializable/ColoredDrawable.cpp
)

# Include directories for Magnum, Bullet, ImGui, and ENet
target_include_directories(MagnumClient PRIVATE
        $<TARGET_PROPERTY:enet,INTERFACE_INCLUDE_DIRECTORIES>
        ${PROJECT_SOURCE_DIR}/externals/enet6/include
        inc
)

# Set C++ standard to C++20
set_property(TARGET MagnumClient PROPERTY CXX_STANDARD 20)

# Link necessary libraries for the client application
target_link_libraries(MagnumClient PRIVATE
        Magnum::Application
        Magnum::GL
        Magnum::Magnum
        Magnum::MeshTools
        Magnum::Primitives
        Magnum::SceneGraph
        Magnum::Shaders
        Magnum::Trade
        MagnumIntegration::Bullet
        MagnumIntegration::ImGui
        Bullet::Dynamics
        BulletDynamics
        BulletCollision
        LinearMath
        Bullet3Common
        enet
)

# SERVER APP
#add_subdirectory(src/server)
# CLIENT APP
#add_subdirectory(src/client)
# WEBSOCKET
add_subdirectory(src/telemetry-client)
# GAME LAUNCHER
add_subdirectory(src/launcher)

# === Windows-specific: copy MinGW DLLs next to executables ===
# Auto-copy MinGW runtime DLLs (only on Windows + MinGW)
if (WIN32 AND MINGW)
    get_filename_component(MINGW_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)

    foreach(dll libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll)
        add_custom_command(TARGET MagnumServer POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${MINGW_BIN_DIR}/${dll}"
                "$<TARGET_FILE_DIR:MagnumServer>"
        )
        add_custom_command(TARGET MagnumClient POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${MINGW_BIN_DIR}/${dll}"
                "$<TARGET_FILE_DIR:MagnumClient>"
        )
    endforeach()
endif()

function(copy_dlls TARGET)
    add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Corrade::Utility>
            $<TARGET_FILE:Magnum::Magnum>
            $<TARGET_FILE:Magnum::GL>
            $<TARGET_FILE:Magnum::Shaders>
            $<TARGET_FILE:Magnum::Trade>
            $<TARGET_FILE:Magnum::MeshTools>
            $<TARGET_FILE:Magnum::SceneGraph>
            $<TARGET_FILE:MagnumIntegration::ImGui>
            $<TARGET_FILE:MagnumIntegration::Bullet>
            $<TARGET_FILE_DIR:${TARGET}>
    )
endfunction()


copy_dlls(MagnumServer)
copy_dlls(MagnumClient )
# Function to copy DLLs after build
