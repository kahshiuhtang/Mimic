#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED
#include "Card.hpp"
#include <vector>
class Deck{
public:
    Card drawCard();
    std::vector<Card> drawCards(int numCards);
    Deck();
private:
    const int  m_DECK_SIZE = 52;
    std::vector<Card> m_pDeckArray;
    bool m_pDrawn[52];
};

#endif // DECK_HPP_INCLUDED
