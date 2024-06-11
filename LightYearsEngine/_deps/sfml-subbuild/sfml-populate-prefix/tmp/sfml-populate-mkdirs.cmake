# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-src"
  "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-build"
  "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-subbuild/sfml-populate-prefix"
  "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Projects/Udemy/LightYears/LightYears/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
