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
