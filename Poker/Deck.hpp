#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED
#include "Card.hpp"
#include <vector>
class Deck{
public:
    Card drawCard();
    std::vector<Card> drawCards(int numCards);
private:
    Card m_pDeckArray[52];
    bool m_pDrawn[52];
};

#endif // DECK_HPP_INCLUDED
