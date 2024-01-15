cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_14)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

set(MPOKER_PROJECT_NAME 
    MPoker)

set(MPOKER_SOURCE_DIR 
    src)

set(MPOKER_EXEC_DIR
    exec)

set(MPOKER_LIBRARIES_DIR
    libs)

set(MPOKER_TESTS_DIR
    tests)   


project(${MPOKER_PROJECT_NAME})

option(TEST "Test" OFF) #  -DTEST=ON
option(DEBUG "Debug" OFF) # -DDEBUG=ON
option(VERBOSE "Test" OFF) #  -DTEST=ON

add_compile_definitions(WARN)
add_compile_definitions(SUCCESS)
add_compile_definitions(ERROR)
if (${DEBUG})
    message("[DEBUG] Build")
    set(CMAKE_BUILD_TYPE Debug)
    add_compile_definitions(VERBOSE)
    add_compile_definitions(DEBUG)
endif()

include_directories(include)

add_subdirectory(${MPOKER_SOURCE_DIR})
# add_subdirectory(${MPOKER_EXEC_DIR})

if (${TEST})
    message("[Tests] Building...")
    add_subdirectory(${MPOKER_TESTS_DIR})
endif()
