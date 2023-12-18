#include "Deck.hpp"
#include <cstdlib>
Deck::Deck(){
    for(int i = 0; i < m_DECK_SIZE; i++){
        m_pDrawn[i] = false;
        Card currCard(Card::Suite(i % 4), Card::Value(i % 13));
        m_pDeckArray[i] = currCard;
    }
}

Card Deck::drawCard(){
    bool needIndex = true;
    Card drawnCard;
    while(needIndex){
        int randIdx = rand() % 52;
        if(m_pDrawn[randIdx] == false){
            needIndex = false;
            m_pDrawn[randIdx] = true;
            drawnCard = m_pDeckArray[randIdx];
        }
    }
    return drawnCard;
}
std::vector<Card> Deck::drawCards(int numCards){
    std::vector<Card> drawnCards;
    for(int i = 0; i < numCards; i++){
        drawnCards.push_back(drawCard());
    }
    return drawnCards;
}
