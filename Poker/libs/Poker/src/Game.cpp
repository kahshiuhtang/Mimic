#include <string>
#include <iostream>
#include "Game.hpp"
bool Game::addPlayer(){
    if(m_GameState != WAITING){
        return false;
    }
}
bool Game::startGame(){
    if(m_GameState == WAITING){
        m_GameState = PREFLOP;
        return true;
    }
    return false;
}
bool Game::nextRound(){
}
bool Game::revealCards(){
}
bool Game::dealCards(){
}
bool Game::bet(){
}
Player* Game::checkWinner(){
    return nullptr;
}
int Game::nextTurn(){

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
}
