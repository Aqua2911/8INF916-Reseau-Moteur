# Install script for directory: C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Corrade" TYPE FILE FILES
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Corrade.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Cpu.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Tags.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Corrade" TYPE FILE FILES
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/configure.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/lib/libCorradeMain.a")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/Containers/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/Interconnect/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/PluginManager/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/TestSuite/cmake_install.cmake")
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/Utility/cmake_install.cmake")

endif()

