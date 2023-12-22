#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include "Poker/Player.hpp"
#include "Poker/Dealer.hpp"
#include "Poker/Card.hpp"
#include <vector>
#include <memory>
class Game
{
public:
    Game();
    bool addPlayer(std::string name, int startingChips);
    bool startGame();
    bool nextRound();
    std::vector<Card> revealCards();
    bool dealCards();
    bool bet();
    Player *checkWinner();
    int nextTurn();
    bool start();

private:
    enum GAMESTATE
    {
        WAITING,
        PREFLOP,
        FLOP,
        TURN,
        RIVER
    };
    std::vector<std::unique_ptr<Player>> m_Players;
    std::unique_ptr<Dealer> m_Dealer;
    std::vector<int> m_CurrentBets;
    std::vector<Card> m_Board;
    int m_Turn;
    int m_CurrentRound;
    int m_BigBlindIndex;
    GAMESTATE m_CurrentGameState;
};

#endif // GAME_HPP_INCLUDED
