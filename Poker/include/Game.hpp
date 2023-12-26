#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include "poker/player.hpp"
#include "poker/dealer.hpp"
#include "poker/card.hpp"
#include "poker/hand_evaluator.hpp"
#include <vector>
#include <memory>
class Game
{
public:
    Game();
    bool addPlayer(std::string name, int startingChips);
    bool startGame();
    bool nextRound();
    bool start();
    bool dealCards();
    bool bet();

    int nextTurn();

    std::vector<Card> revealCards();
    Player *checkWinner();

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
    HandEvaluator evaluator;
};

#endif // GAME_HPP_INCLUDED
