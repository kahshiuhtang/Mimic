set(SRC_FILES   
    card.cpp
    dealer.cpp
    deck.cpp
    game.cpp
    hand_evaluator.cpp
    player.cpp
    )

add_library(source_lib ${SRC_FILES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
# Create an executable for nodes
add_executable(server server.cpp)
target_link_libraries(server source_lib)

# Create an executable for server
add_executable(client client.cpp)
target_link_libraries(client source_lib)

