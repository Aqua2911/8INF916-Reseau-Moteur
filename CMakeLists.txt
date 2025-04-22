cmake_minimum_required(VERSION 3.10)
project(MagnumBootstrap)

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

# Main executable
add_executable(MagnumBootstrap
        src/main.cpp
        src/Serializable/InstanceData.cpp
        src/Serializable/Serializable.cpp
)


# Include directories for other components
message(STATUS "ENet include path: ${PROJECT_SOURCE_DIR}/externals/enet6/include")
target_include_directories(MagnumBootstrap PRIVATE
        $<TARGET_PROPERTY:enet,INTERFACE_INCLUDE_DIRECTORIES>
)
target_include_directories(MagnumBootstrap PUBLIC inc)
target_include_directories(MagnumBootstrap PRIVATE ${PROJECT_SOURCE_DIR}/externals/enet6/include)


set_property(TARGET MagnumBootstrap PROPERTY CXX_STANDARD 20)

# Link required libraries
target_link_libraries(MagnumBootstrap PRIVATE
        Magnum::Application
        Magnum::GL
        Magnum::Magnum
        Magnum::MeshTools
        Magnum::Primitives
        Magnum::SceneGraph
        Magnum::Shaders
        Magnum::Trade
        MagnumIntegration::Bullet
        Bullet::Dynamics
        MagnumIntegration::ImGui
        BulletDynamics
        BulletCollision
        LinearMath
        Bullet3Common
        enet)  # Link ENet6 library built from source


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


