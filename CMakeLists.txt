cmake_minimum_required(VERSION 3.30)
project(MagnumBootstrap)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

add_subdirectory(externals)
find_package(Magnum REQUIRED
        GL
        GlfwApplication
        Primitives
        Shaders
        Trade
        MeshTools
        Primitives
        SceneGraph)
find_package(MagnumIntegration REQUIRED ImGui Bullet)
find_package(Bullet REQUIRED Dynamics)

# ENet6 setup
include_directories(externals/enet6/include)  # Update this if ENet6 is in externals/enet6

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

# Main executable
add_executable(MagnumBootstrap
        src/main.cpp)

# Now specify the link directories for the MagnumBootstrap target
target_link_directories(MagnumBootstrap PRIVATE externals/enet6/lib)  # Set to ENet6's lib folder

target_include_directories(MagnumBootstrap PUBLIC inc)

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
        Bullet::Dynamics
        MagnumIntegration::ImGui
        BulletDynamics
        BulletCollision
        LinearMath
        Bullet3Common
        enet6)  # Link ENet6 library






add_executable(MagnumBootstrap2
        src/main2.cpp)

target_include_directories(MagnumBootstrap2 PUBLIC inc)
set_property(TARGET MagnumBootstrap2 PROPERTY CXX_STANDARD 20)
target_link_libraries(MagnumBootstrap2 PRIVATE
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
        Bullet3Common)