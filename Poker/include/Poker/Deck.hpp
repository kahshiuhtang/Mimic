#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED
#include "card.hpp"
#include <vector>
class Deck
{
public:
    Deck();
    Card drawCard();
    std::vector<Card> drawCards(int numCards);
    bool resetDeck();

private:
    const int DECK_SIZE = 52;
    const int NUM_CARD_SUITES = 4;
    const int NUM_CARD_VALUES = 13;
    int m_numRemainingCards;
    std::vector<Card> m_pDeckArray;
    bool fillDeck();
};

#endif // DECK_HPP_INCLUDED
