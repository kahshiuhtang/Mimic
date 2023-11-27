#ifndef DEALER_HPP_INCLUDED
#define DEALER_HPP_INCLUDED
#include "Deck.hpp"
#include <vector>
class Dealer{
public:
    bool showCards(int numCards);
    bool dealCards();
public:
    std::vector<Deck> m_Decks;
    bool newDeck();
};

#endif // DEALER_HPP_INCLUDED
