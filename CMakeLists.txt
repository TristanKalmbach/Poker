cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/*.cpp src/*.hpp)

# Set options for this project.

project (Poker)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

set (PROJECT_SOURCE_DECLARATION_DIRECTORY ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DEFINITION_DIRECTORY ${PROJECT_SOURCE_DIR}/src)

# Set options used by "CMake".
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/macros")

# Set options used by "FindBoost.cmake".
# Either specify BOOST_ROOT or BOOST_INCLUDEDIR and BOOST_LIBRARYDIR.
# I am using "MinGW Distro" in this example, but also a relative path, e. g.
# "vendor/boost" can be specified.
set (BOOST_ROOT "E:/local/boost_1_65_1")
#set (BOOST_INCLUDEDIR "C:/MinGW/include")
set (BOOST_LIBRARYDIR "E:/local/boost_1_65_1/lib64-msvc-14.1")
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)

# Load settings for the external project "Boost".
# The components "system" and "filesystem" from "Boost" version 1.64.0 or
# greater are required.
find_package (Boost 1.65.1 REQUIRED COMPONENTS system filesystem log)
if (Boost_FOUND)
  # From the offical documentation:
  # Add include directories to the build. [...] If the SYSTEM option is given,
  # the compiler will be told the directories are meant as system include
  # directories on some platforms (signalling this setting might achieve effects
  # such as the compiler skipping warnings [...])."
  include_directories (SYSTEM ${Boost_INCLUDE_DIR})

  # From the offical documentation:
  # "Specify directories in which the linker will look for libraries. [...] Note
  # that this command is rarely necessary. Library locations returned by
  # find_package() and find_library() are absolute paths. Pass these absolute
  # library file paths directly to the target_link_libraries() command. CMake
  # will ensure the linker finds them."
  #link_directories (${Boost_LIBRARY_DIRS})
endif ()

# "Add an executable to the project using the specified source files."
add_executable (${PROJECT_NAME} ${SOURCES})

# "Link a target to given libraries."
target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES})