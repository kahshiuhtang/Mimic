#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include <utility>
#include "Card.hpp"
class Player{
public:
    enum Move{CALL, RAISE, CHECK, FOLD};
    bool placeMove();
    Player(std::string name);
private:
    float m_nTotalChips;
    long long m_nId;
    std::string name;
    int m_nWins;
};

#endif // PLAYER_HPP_INCLUDED
