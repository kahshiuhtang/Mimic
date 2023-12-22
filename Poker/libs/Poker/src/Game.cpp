#include <string>
#include <iostream>
#include <memory>
#include "Game.hpp"
#include "Player.hpp"
#include "Card.hpp"
#include "Dealer.hpp"
Game::Game() : m_Turn(0), m_CurrentGameState(WAITING), m_BigBlindIndex(0), m_CurrentRound(0)
{
    std::unique_ptr<Dealer> m_Dealer = std::make_unique<Dealer>(1);
}
bool Game::addPlayer(std::string name, int startingChips)
{
    if (m_CurrentGameState != WAITING)
    {
        return false;
    }
    m_Players.push_back(std::make_unique<Player>(name, startingChips));
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
    m_CurrentRound += 1;
    return true;
}
bool Game::revealCards()
{
    if (m_CurrentGameState == WAITING || m_CurrentGameState == PREFLOP)
    {
        return false;
    }
    std::vector<std::unique_ptr<Card>> *cards;
    if (m_CurrentGameState == FLOP)
    {
    }
    else if (m_CurrentGameState == TURN || m_CurrentGameState == RIVER)
    {
    }
    return true;
}
bool Game::dealCards()
{
    return true;
}
bool Game::bet()
{
    return true;
}
Player *Game::checkWinner()
{
    return nullptr;
}
int Game::nextTurn()
{
    return 0;
}

bool Game::start()
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
