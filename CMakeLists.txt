# Make sure you have at least CMake 3.8
cmake_minimum_required(VERSION 3.8)

# For all compilers, set standard to C++17
set(CMAKE_CXX_STANDARD 17)

# On VS make sure the C++ 17 compile flags are enabled
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

# set macro-directory
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/macros")

# Meta information about the project
set(META_PROJECT_NAME        "Poker")
set(META_PROJECT_DESCRIPTION "Five Card Draw Poker Simulator")
set(META_AUTHOR_ORGANIZATION "Tristan Kalmbach")
set(META_AUTHOR_DOMAIN       "https://github.com/TristanKalmbach/Poker")
set(META_AUTHOR_MAINTAINER   "tristan.kalmbach@gmail.com")
set(META_VERSION_MAJOR       "0")
set(META_VERSION_MINOR       "1")
set(META_VERSION_PATCH       "1")
set(META_VERSION_REVISION    "${GIT_REV}")
set(META_VERSION             "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")
set(META_NAME_VERSION        "${META_PROJECT_NAME} v${META_VERSION} (${META_VERSION_REVISION})")
set(META_CMAKE_INIT_SHA      "${GIT_SHA1}")

string(MAKE_C_IDENTIFIER ${META_PROJECT_NAME} META_PROJECT_ID)
string(TOUPPER ${META_PROJECT_ID} META_PROJECT_ID)

#include macros
include(GroupSources)
include(cmake/options.cmake)

# add core sources
add_subdirectory(src)