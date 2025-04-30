# Install script for directory: /home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL

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
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumGL.so.2.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumGL.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumGL.so.2.4"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumGL.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumGL.so.2.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMagnumGL.so.2"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/Release/lib/libMagnumGL.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/GL" TYPE FILE FILES
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/AbstractFramebuffer.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/AbstractObject.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/AbstractQuery.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/AbstractShaderProgram.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/AbstractTexture.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Attribute.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Buffer.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Context.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/CubeMapTexture.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/DefaultFramebuffer.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Extensions.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Framebuffer.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/GL.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Mesh.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/MeshView.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/OpenGL.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/PixelFormat.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Renderbuffer.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/RenderbufferFormat.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Renderer.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Sampler.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Shader.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Texture.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/TextureFormat.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/TimeQuery.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/Version.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/visibility.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/PipelineStatisticsQuery.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/RectangleTexture.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/BufferImage.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/PrimitiveQuery.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/TextureArray.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/TransformFeedback.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/DebugOutput.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/BufferTexture.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/BufferTextureFormat.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/CubeMapTextureArray.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/ImageFormat.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/MultisampleTexture.h"
    "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src/src/Magnum/GL/SampleQuery.h"
    )
endif()

