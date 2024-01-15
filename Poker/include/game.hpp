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
    bool startInputHandle();
    bool nextRound();
    bool dealCards();
    bool recordPlayerBet();

    int nextTurn();

    std::vector<std::shared_ptr<Card>> revealCards();
    std::shared_ptr<Player> checkWinner();

    const int CARDS_PER_PLAYER_HAND = 2;

private:
    enum GAMESTATE
    {
        WAITING,
        PREFLOP,
        FLOP,
        TURN,
        RIVER
    };
    std::vector<std::shared_ptr<Player>> m_Players;
    std::unique_ptr<Dealer> m_Dealer;
    std::vector<int> m_CurrentBets;
    std::vector<Card> m_Board;
    int m_Turn;
    int m_CurrentRound;
    int m_BigBlindIndex;
    bool m_DealtPlayerCards;
    GAMESTATE m_CurrentGameState;
    std::unique_ptr<HandEvaluator> m_Evaluator;
};

#endif // GAME_HPP_INCLUDED
