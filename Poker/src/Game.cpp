#include <string>
#include <iostream>
#include <memory>
#include "Game.hpp"
#include "Poker/Player.hpp"
#include "Poker/Card.hpp"
#include "Poker/Dealer.hpp"
Game::Game() : m_Turn{0}, m_CurrentGameState{WAITING}, m_BigBlindIndex{0}, m_CurrentRound{0}
{
    std::unique_ptr<Dealer> m_Dealer = std::make_unique<Dealer>();
}
bool Game::addPlayer(std::string name, int startingChips)
{
    if (m_CurrentGameState != WAITING)
    {
        return false;
    }
    m_Players.push_back(std::make_unique<Player>(name, startingChips));
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
    m_CurrentRound += 1;
    return true;
}
std::vector<Card> Game::revealCards()
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
