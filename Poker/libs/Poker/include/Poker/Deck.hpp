#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED
#include "Card.hpp"
#include <vector>
class Deck
{
public:
    Deck();
    Card drawCard();
    std::vector<Card> drawCards(int numCards);
    bool resetDeck();

private:
    const int m_DECK_SIZE = 52;
    int m_numRemainingCards;
    std::vector<Card> m_pDeckArray;
    bool fillDeck();
};

#endif // DECK_HPP_INCLUDED
