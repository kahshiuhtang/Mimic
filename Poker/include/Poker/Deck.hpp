#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED
#include "card.hpp"
#include <vector>
class Deck
{
public:
    Deck();

    Card drawCard();
    bool resetDeck();
    std::vector<Card> drawCards(int numCards);

private:
    const int DECK_SIZE = 52;
    const int NUM_CARD_SUITES = 4;
    const int NUM_CARD_VALUES = 13;
    bool fillDeck();
    int m_numRemainingCards;
    std::vector<Card> m_pDeckArray;
};

#endif // DECK_HPP_INCLUDED
