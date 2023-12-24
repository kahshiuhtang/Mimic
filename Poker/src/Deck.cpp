#include "Poker/Deck.hpp"
#include <cstdlib>
#include <algorithm>
Deck::Deck() : m_numRemainingCards(52)
{
    fillDeck();
}

Card Deck::drawCard()
{
    if (m_numRemainingCards <= 0)
    {
    }
    Card drawnCard;
    int randIdx = rand() % m_numRemainingCards;
    drawnCard = m_pDeckArray[randIdx];
    m_numRemainingCards -= 1;
    std::swap(m_pDeckArray[randIdx], m_pDeckArray[m_numRemainingCards]);
    return drawnCard;
}
std::vector<Card> Deck::drawCards(int numCards)
{
    std::vector<Card> drawnCards;
    for (int i = 0; i < numCards; i++)
    {
        drawnCards.push_back(drawCard());
    }
    return drawnCards;
}

bool Deck::resetDeck()
{
    m_pDeckArray.clear();
    m_numRemainingCards = 52;
    fillDeck();
    return true;
}

bool Deck::fillDeck()
{
    for (int i = 0; i < DECK_SIZE; i++)
    {
        Card currCard(Card::Suite(i % 4), Card::Value(i % 13));
        m_pDeckArray[i] = currCard;
    }
    return true;
}
