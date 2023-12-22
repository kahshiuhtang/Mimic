#include "Dealer.hpp"

Dealer::Dealer(int numDecks)
: m_CurrentDecks(numDecks){
    for(int i = 0; i < numDecks; i++){

    }
}

bool Dealer::showCards(int numCards){
    return true;
}
bool Dealer::dealCards(){
    return false;
}
