if(CMAKE_COMPILER_IS_GNUCXX AND NOT MINGW)
  add_definitions(-fno-delete-null-pointer-checks)
endif()

file(GLOB_RECURSE sources_Player Player/*.cpp Player/*.hpp)
file(GLOB_RECURSE sources_Dealer Dealer/*.cpp Dealer/*.hpp)
file(GLOB_RECURSE sources_Cards Cards/*.cpp Cards/*.hpp)
file(GLOB_RECURSE sources_Deck Deck/*.hpp Deck/*.cpp)
file(GLOB_RECURSE sources_Controller Controller/*.cpp Controller/*.hpp)
file(GLOB_RECURSE sources_Utility Utility/*.cpp Utility/*hpp)
file(GLOB sources_localdir *.cpp *.hpp)

set(game_STAT_SRCS
  ${game_STAT_SRCS}
  ${sources_Player}
  ${sources_Dealer}
  ${sources_Deck}
  ${sources_Cards}
  ${sources_Controller}
  ${sources_Utility}
  ${sources_localdir}
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/Player
  ${CMAKE_CURRENT_SOURCE_DIR}/Dealer
  ${CMAKE_CURRENT_SOURCE_DIR}/Deck
  ${CMAKE_CURRENT_SOURCE_DIR}/Cards
  ${CMAKE_CURRENT_SOURCE_DIR}/Controller
  ${CMAKE_CURRENT_SOURCE_DIR}/Utility
)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(game STATIC
  ${game_STAT_SRCS}
)