#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include <utility>
#include <string>
#include "Card.hpp"
class Player{
public:
    enum Move{CALL, RAISE, CHECK, FOLD};
    bool placeMove();
    bool updateChips();
    Player(std::string name);
private:
    float m_nTotalChips;
    std::string m_sId;
    std::string m_sName;
    int m_nWins;
};

#endif // PLAYER_HPP_INCLUDED
