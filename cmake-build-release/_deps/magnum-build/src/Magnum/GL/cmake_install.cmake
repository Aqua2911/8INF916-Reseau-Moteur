# Install script for directory: C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/lib/libMagnumGL.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/Release/bin/libMagnumGL.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnumGL.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnumGL.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/JetBrains/CLion 2024.3.2/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libMagnumGL.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/GL" TYPE FILE FILES
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/AbstractFramebuffer.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/AbstractObject.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/AbstractQuery.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/AbstractShaderProgram.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/AbstractTexture.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Attribute.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Buffer.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Context.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/CubeMapTexture.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/DefaultFramebuffer.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Extensions.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Framebuffer.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/GL.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Mesh.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/MeshView.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/OpenGL.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/PixelFormat.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Renderbuffer.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/RenderbufferFormat.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Renderer.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Sampler.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Shader.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Texture.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/TextureFormat.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/TimeQuery.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/Version.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/visibility.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/PipelineStatisticsQuery.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/RectangleTexture.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/BufferImage.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/PrimitiveQuery.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/TextureArray.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/TransformFeedback.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/DebugOutput.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/BufferTexture.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/BufferTextureFormat.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/CubeMapTextureArray.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/ImageFormat.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/MultisampleTexture.h"
    "C:/Users/jpkpg/CLEMENT-DEV/.GIT-REMOTE/8INF916-Reseau-Moteur/cmake-build-release/_deps/magnum-src/src/Magnum/GL/SampleQuery.h"
    )
endif()

