if(CMAKE_COMPILER_IS_GNUCXX AND NOT MINGW)
  add_definitions(-fno-delete-null-pointer-checks)
endif()

add_subdirectory(Game)

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
target_link_libraries(Poker game)