#ifndef DEALER_HPP_INCLUDED
#define DEALER_HPP_INCLUDED
#include "Deck.hpp"
#include <vector>
class Dealer{
public:
    bool showCards(int numCards);
    bool dealCards();
    bool newDeck();
    Dealer(int numDecks);
private:
    std::vector<Deck> m_Decks;
    int m_CurrentDecks;
};

#endif // DEALER_HPP_INCLUDED
