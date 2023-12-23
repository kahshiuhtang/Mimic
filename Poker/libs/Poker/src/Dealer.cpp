#include "Dealer.hpp"
#include <vector>
Dealer::Dealer()
{
}
std::vector<Card> Dealer::dealCards(int numCards)
{
    std::vector<Card> drawnCards;
    for (int i = 0; i < numCards; i++)
    {
        drawnCards.push_back(m_CurrentDeck.drawCard());
    }
    return drawnCards;
}
bool Dealer::resetDeck()
{
    return m_CurrentDeck.resetDeck();
}
