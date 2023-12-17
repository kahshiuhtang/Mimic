cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MPOKER_PROJECT_NAME 
    MPoker)

set(MPOKER_SOURCE_DIR 
    src)

set(MPOKER_SOURCE
    ${MPOKER_SOURCE_DIR}/main.cpp)

set(MPOKER_LIBRARIES_DIR
    libs)

set(MPOKER_LIBRARIES
    poker)

project(${MPOKER_PROJECT_NAME})

add_executable(${MPOKER_PROJECT_NAME} ${MPOKER_SOURCE})

foreach(LIBRARY ${MPOKER_LIBRARIES})
    add_subdirectory("${MPOKER_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${MPOKER_PROJECT_NAME} ${MPOKER_LIBRARIES})

