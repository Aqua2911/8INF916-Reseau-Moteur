# Install script for directory: /home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumSceneGraph.so.2.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumSceneGraph.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumSceneGraph.so.2.4"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumSceneGraph.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumSceneGraph.so.2.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumSceneGraph.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumSceneGraph.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/SceneGraph" TYPE FILE FILES
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractFeature.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractFeature.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractGroupedFeature.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractObject.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTransformation.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslation.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotation2D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotation3D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotationScaling2D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotationScaling3D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Animable.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Animable.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/AnimableGroup.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Camera.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Camera.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Drawable.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Drawable.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/DualComplexTransformation.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/DualQuaternionTransformation.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation2D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation2D.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation3D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation3D.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/FeatureGroup.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/FeatureGroup.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation2D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation2D.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation3D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation3D.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Object.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Object.hpp"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/Scene.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/SceneGraph.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/TranslationTransformation.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/TranslationRotationScalingTransformation2D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/TranslationRotationScalingTransformation3D.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/SceneGraph/visibility.h"
    )
endif()

