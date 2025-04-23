cmake_minimum_required(VERSION 3.10)
project(MagnumServer)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})


set(USE_TLS  OFF CACHE BOOL "Disable TLS support in IXWebSocket" FORCE)
set(USE_ZLIB OFF CACHE BOOL "Disable Zlib support in IXWebSocket" FORCE)

add_subdirectory(externals/IXWebSocket)

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
)

target_include_directories(MagnumServer PRIVATE
        $<TARGET_PROPERTY:enet,INTERFACE_INCLUDE_DIRECTORIES>
        inc
        ${PROJECT_SOURCE_DIR}/externals/enet6/include
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
add_executable(ServerApp src/server/main.cpp)

target_include_directories(ServerApp PRIVATE
        ${PROJECT_SOURCE_DIR}/externals/cpp-httplib
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)

target_link_libraries(ServerApp PRIVATE ws2_32)
set_property(TARGET ServerApp PROPERTY CXX_STANDARD 20)


# CLIENT APP
add_executable(ClientApp src/client/main.cpp)

target_include_directories(ClientApp PRIVATE
        ${PROJECT_SOURCE_DIR}/externals/cpp-httplib
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)

target_link_libraries(ClientApp PRIVATE ws2_32)
set_property(TARGET ClientApp PROPERTY CXX_STANDARD 20)

# WEBSOCKET
add_executable(WebSocketClient src/telemetry-client/main.cpp)
target_link_libraries(WebSocketClient PRIVATE ixwebsocket)
target_include_directories(WebSocketClient PRIVATE
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)
set_property(TARGET WebSocketClient PROPERTY CXX_STANDARD 20)


