
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test files
set(TEST_SOURCES
  hand_eval_tests.cpp
)

enable_testing()

add_executable(tests ${TEST_SOURCES})

#find_package(cppzmq)

# Link to src files, cppzmq, and gtest
target_link_libraries(
  tests
  # cppzmq
  source_lib 
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)