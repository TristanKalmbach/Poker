if(CMAKE_COMPILER_IS_GNUCXX AND NOT MINGW)
  add_definitions(-fno-delete-null-pointer-checks)
endif()

add_subdirectory(Game) 

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

file(GLOB sources_localdir *.cpp *.hpp)

set(Poker_Srcs
  ${sources_localdir}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/Game
  ${CMAKE_SOURCE_DIR}/src/Game/Player
  ${CMAKE_SOURCE_DIR}/src/Game/Dealer
  ${CMAKE_SOURCE_DIR}/src/Game/Deck
  ${CMAKE_SOURCE_DIR}/src/Game/Cards
  ${CMAKE_SOURCE_DIR}/src/Game/Controller
  ${CMAKE_SOURCE_DIR}/src/Game/Utility
)

add_executable(Poker ${Poker_Srcs})
target_link_libraries(Poker game ${Boost_LIBRARIES})