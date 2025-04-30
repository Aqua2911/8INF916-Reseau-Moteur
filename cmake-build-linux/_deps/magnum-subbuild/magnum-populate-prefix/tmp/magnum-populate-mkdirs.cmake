# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-src"
  "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-build"
  "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-subbuild/magnum-populate-prefix"
  "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-subbuild/magnum-populate-prefix/tmp"
  "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-subbuild/magnum-populate-prefix/src/magnum-populate-stamp"
  "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-subbuild/magnum-populate-prefix/src"
  "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-subbuild/magnum-populate-prefix/src/magnum-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-subbuild/magnum-populate-prefix/src/magnum-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ensea/UQAC/8INF916-Reseau-Moteur/cmake-build-linux/_deps/magnum-subbuild/magnum-populate-prefix/src/magnum-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
