#include <string>
#include <iostream>
#include "Game.hpp"
bool Game::addPlayer(){
    if(m_GameState != WAITING){
        return false;
    }
    return true;
}
bool Game::startGame(){
    if(m_GameState == WAITING){
        m_GameState = PREFLOP;
        return true;
    }
    return false;
}
bool Game::nextRound(){
    return true;
}
bool Game::revealCards(){
    return true;
}
bool Game::dealCards(){
    return true;
}
bool Game::bet(){
    return true;
}
Player* Game::checkWinner(){
    return nullptr;
}
int Game::nextTurn(){
    return 0;
}

bool Game::start(){
    std::string input;
    while(true){
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit" || input == "quit") {
            break;
        }
    }
    return true;
}
