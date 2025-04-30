# Install script for directory: C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/lib/libCorradeUtility.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/bin/libCorradeUtility.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libCorradeUtility.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libCorradeUtility.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/JetBrains/CLion 2024.3.2/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libCorradeUtility.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Corrade/Utility" TYPE FILE FILES
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Algorithms.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Arguments.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/AbstractHash.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Assert.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/BitAlgorithms.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Configuration.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/ConfigurationGroup.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/ConfigurationValue.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Debug.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/DebugAssert.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/DebugStl.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/DebugStlStringView.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Endianness.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/EndiannessBatch.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Format.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/FormatStl.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/FormatStlStringView.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/IntrinsicsSse2.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/IntrinsicsSse3.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/IntrinsicsSsse3.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/IntrinsicsSse4.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/IntrinsicsAvx.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Json.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/JsonWriter.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Macros.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Math.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Memory.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Move.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/MurmurHash2.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Path.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Resource.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Sha1.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/String.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/StlForwardArray.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/StlForwardString.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/StlForwardTuple.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/StlForwardTupleSizeElement.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/StlForwardVector.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/StlMath.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/System.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/TypeTraits.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Unicode.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/utilities.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Utility.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/VisibilityMacros.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/visibility.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Directory.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/FileWatcher.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/Tweakable.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-src/src/Corrade/Utility/TweakableParser.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/bin/corrade-rc.exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc.exe")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/JetBrains/CLion 2024.3.2/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc.exe")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/corrade-build/src/Corrade/Utility/CMakeFiles/corrade-rc.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
endif()

