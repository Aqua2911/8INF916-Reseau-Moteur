# Install script for directory: C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/lib/libMagnum.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/bin/libMagnum.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnum.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnum.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/JetBrains/CLion 2024.3.2/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnum.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum" TYPE FILE FILES
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/AbstractResourceLoader.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/British.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/DimensionTraits.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/FileCallback.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Image.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/ImageFlags.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/ImageView.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Magnum.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Mesh.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/PixelFormat.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/PixelStorage.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Resource.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/ResourceManager.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Sampler.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Tags.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Timeline.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Types.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/VertexFormat.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/visibility.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/Array.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum" TYPE FILE FILES
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/configure.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/version.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/Animation/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/Math/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/Platform/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/DebugTools/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/GL/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/MaterialTools/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/MeshTools/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/Primitives/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/SceneGraph/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/SceneTools/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/Shaders/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/ShaderTools/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/Text/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/TextureTools/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-build/src/Magnum/Trade/cmake_install.cmake")

endif()

