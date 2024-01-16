#include <string>
#include <iostream>
#include <memory>
#include "game.hpp"
#include "poker/player.hpp"
#include "poker/card.hpp"
#include "poker/dealer.hpp"
#include "poker/hand_evaluator.hpp"
Game::Game() : m_Turn{0}, m_CurrentGameState{WAITING}, m_BigBlindIndex{0}, m_CurrentRound{0}, m_DealtPlayerCards{false}
{
     m_PrevStartingTurn = 0;
     m_Turn = 0;
     m_Dealer = std::make_unique<Dealer>();
     m_Evaluator = std::make_unique<HandEvaluator>();
}
bool Game::addPlayer(std::string name, int startingChips)
{
    if (m_CurrentGameState != WAITING)
    {
        return false;
    }
    m_Players.push_back(std::make_shared <Player>(name, startingChips));
    m_CurrentBets.push_back(0);
    return true;
}
bool Game::startGame()
{
    if (m_CurrentGameState == WAITING)
    {
        m_CurrentGameState = PREFLOP;
        return true;
    }
    return false;
}
bool Game::nextRound()
{
    if (m_CurrentGameState != RIVER)
    {
        return false;
    }
    for(int i = 0; i < m_CurrentBets.size(); i++){
        
    }
    m_CurrentRound += 1;
    return true;
}
std::vector<std::shared_ptr<Card>> Game::revealCards()
{
    if (m_CurrentGameState == WAITING || m_CurrentGameState == PREFLOP)
    {
    }
    int cardsToReveal = 1;
    if (m_CurrentGameState == TURN || m_CurrentGameState == RIVER)
    {
        cardsToReveal = 2;
    }
    return m_Dealer->dealCards(cardsToReveal);
}
bool Game::dealCards()
{
    for(int i = 0; i < m_Players.size(); i++){
        m_Players[i]->currentHand = m_Dealer->dealCards(CARDS_PER_PLAYER_HAND);
    }
    m_DealtPlayerCards = true;
    return true;
}

std::shared_ptr<Player> Game::checkWinner()
{
    for(int i = 0; i < m_Players.size(); i++){

    }
    return nullptr;
}
int Game::nextTurn()
{
    m_Turn = (m_Turn +1) % m_Players.size();
    return 0;
}

bool Game::startInputHandle()
{
    std::string input;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit" || input == "quit")
        {
            break;
        }
    }
    return true;
}
