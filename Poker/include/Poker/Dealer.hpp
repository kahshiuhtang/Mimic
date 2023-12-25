#ifndef DEALER_HPP_INCLUDED
#define DEALER_HPP_INCLUDED
#include "deck.hpp"
#include <vector>
class Dealer
{
public:
    Dealer();
    std::vector<Card> dealCards(int numCards);
    bool resetDeck();

private:
    Deck m_CurrentDeck;
};

#endif // DEALER_HPP_INCLUDED
