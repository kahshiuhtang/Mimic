#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include <utility>
class Player{
public:
    enum Move{CALL, RAISE, CHECK, FOLD};
    Move getMove();
private:
    float m_TotalChips;
    int wins;
};

#endif // PLAYER_HPP_INCLUDED
