# Install script for directory: /home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools

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
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumMeshTools.so.2.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumMeshTools.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumMeshTools.so.2.4"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumMeshTools.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumMeshTools.so.2.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumMeshTools.so.2"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumMeshTools.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/MeshTools" TYPE FILE FILES
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/BoundingVolume.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Combine.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/CompressIndices.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Concatenate.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Copy.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Duplicate.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Filter.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/FlipNormals.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/GenerateIndices.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/GenerateLines.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/GenerateNormals.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Interleave.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/InterleaveFlags.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/RemoveDuplicates.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Subdivide.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Tipsify.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Transform.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/visibility.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/CombineIndexedArrays.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/FilterAttributes.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Reference.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/Compile.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/FullScreenTriangle.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/MeshTools/CompileLines.h"
    )
endif()

