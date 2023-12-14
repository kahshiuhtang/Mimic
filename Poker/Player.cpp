#include <uuid>
#include "Player.hpp"

Player::Player(std::string name, int startingChips) :
    m_sName(name), m_nTotalChips(startingChips){
    //m_sId = std::uuid::random_generator()();
    m_nTotalWins = 0;
}
bool Player::updateChips(int chipDifference){
    m_nTotalChips += chipDifference;
}
