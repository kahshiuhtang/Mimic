#include "poker/deck.hpp"
#include <cstdlib>
#include <memory>
#include <algorithm>
Deck::Deck() : m_numRemainingCards(52)
{
    fillDeck();
}

std::shared_ptr<Card> Deck::drawCard()
{
    if (m_numRemainingCards <= 0)
    {
        return nullptr;
    }
    std::shared_ptr<Card> drawnCard;
    int randIdx = rand() % m_numRemainingCards;
    drawnCard = m_pDeckArray[randIdx];
    m_numRemainingCards -= 1;
    std::swap(m_pDeckArray[randIdx], m_pDeckArray[m_numRemainingCards]);
    return drawnCard;
}
std::vector<std::shared_ptr<Card>> Deck::drawCards(int numCards)
{
    std::vector<std::shared_ptr<Card>> drawnCards;
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
        m_pDeckArray[i] = std::make_shared<Card>(Card::Suite(i % 4), Card::Value(i % 13));
    }
    return true;
}
