#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "card.hpp"
class Player
{
public:
    enum Move
    {
        CALL,
        RAISE,
        CHECK,
        FOLD
    };
    std::vector<std::shared_ptr<Card>> currentHand;
    bool placeMove();
    bool updateChips(int numChips);
    Player(std::string name, int startingChips);

private:
    float m_nTotalChips;
    int m_nTotalWins;

    std::string m_sId;
    std::string m_sName;
};

#endif // PLAYER_HPP_INCLUDED
