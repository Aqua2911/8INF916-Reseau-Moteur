cmake_minimum_required(VERSION 3.10)
project(MagnumBootstrap)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

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
add_executable(MagnumBootstrap
        src/main.cpp
        src/Serializable/InstanceData.cpp
        src/Serializable/Serializable.cpp
)

target_include_directories(MagnumBootstrap PRIVATE
        $<TARGET_PROPERTY:enet,INTERFACE_INCLUDE_DIRECTORIES>
        inc
        ${PROJECT_SOURCE_DIR}/externals/enet6/include
)

set_property(TARGET MagnumBootstrap PROPERTY CXX_STANDARD 20)

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
        MagnumIntegration::ImGui
        Bullet::Dynamics
        BulletDynamics
        BulletCollision
        LinearMath
        Bullet3Common
        enet
)

# =======================
# Dedicated Server Target
# =======================
add_executable(MagnumDedicatedServer
        src/server_main.cpp
)

# Console subsystem for Windows (avoids WinMain issue)
if (WIN32)
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_link_options(MagnumDedicatedServer PRIVATE -mconsole -Wl,--subsystem,console)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_link_options(MagnumDedicatedServer PRIVATE /SUBSYSTEM:CONSOLE)
    endif()
endif()


set_property(TARGET MagnumDedicatedServer PROPERTY CXX_STANDARD 20)

target_link_libraries(MagnumDedicatedServer PRIVATE
        enet
        Bullet::Dynamics
        BulletCollision
        LinearMath
)
