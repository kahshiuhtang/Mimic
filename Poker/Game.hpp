#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include "Player.hpp"
#include "Dealer.hpp"
#include <vector>
class Game{
public:
    bool addPlayer();
    bool startGame();
    bool nextRound();
    bool revealCards();
    bool dealCards();
    bool bet();
    Player * checkWinner();
    int nextTurn();
private:
    enum GAMESTATE{WAITING, PREFLOP, FLOP, TURN, RIVER};
    std::vector<Player> m_Players;
    Player * m_CurrentPlayer;
    int m_Turn;
    int m_CurrentRound;
    int m_BigBlindIndex;
    GAMESTATE m_GameState;
};


#endif // GAME_HPP_INCLUDED
