# Install script for directory: C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MagnumServer")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Program Files/JetBrains/CLion 2024.3.2/bin/mingw/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/lib/libMagnumTrade.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/bin/libMagnumTrade.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnumTrade.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnumTrade.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/JetBrains/CLion 2024.3.2/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnumTrade.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/Trade" TYPE FILE FILES
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/AbstractImporter.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/AbstractImageConverter.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/AbstractSceneConverter.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/AnimationData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/ArrayAllocator.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/CameraData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/Data.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/FlatMaterialData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/ImageData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/LightData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/MaterialData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/MaterialLayerData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/MeshData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/PbrClearCoatMaterialData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/PbrMetallicRoughnessMaterialData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/PbrSpecularGlossinessMaterialData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/PhongMaterialData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/SceneData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/SkinData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/TextureData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/Trade.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/visibility.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/AbstractMaterialData.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/MeshData2D.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/MeshData3D.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/MeshObjectData2D.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/MeshObjectData3D.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/ObjectData2D.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Trade/ObjectData3D.h"
    )
endif()

