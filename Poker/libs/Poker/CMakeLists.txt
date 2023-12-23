cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME PokerLib)

set(LIBRARY_NAME Poker)

set(LIBRARY_HEADERS_DIR
    include/${LIBRARY_NAME}
)
set(LIBRARY_HEADERS
    ${LIBRARY_HEADERS_DIR}/Card.hpp
    ${LIBRARY_HEADERS_DIR}/Dealer.hpp
    ${LIBRARY_HEADERS_DIR}/Deck.hpp
    ${LIBRARY_HEADERS_DIR}/HandEvaluator.hpp
    ${LIBRARY_HEADERS_DIR}/Player.hpp
)
set(LIBRARY_SOURCE_DIR
    src
)
set(LIBRARY_SOURCE
    ${LIBRARY_SOURCE_DIR}/Card.cpp
    ${LIBRARY_SOURCE_DIR}/Dealer.cpp
    ${LIBRARY_SOURCE_DIR}/Deck.cpp
    ${LIBRARY_SOURCE_DIR}/Game.cpp
    ${LIBRARY_SOURCE_DIR}/Player.cpp
)

project(${PROJECT_NAME})

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCE}
)

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
set(LIBRARY_TESTS_SOURCE 
    tests)
enable_testing()
add_executable(tests ${LIBRARY_TESTS_SOURCE}/tests_handEvaluator.cpp)
target_link_libraries(
  tests
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(tests)