#ifndef HANDEVALUATOR_HPP_INCLUDED
#define HANDEVALUATOR_HPP_INCLUDED
#include "Card.hpp"
#include <vector>
class HandEvaluator{
    public:
        enum HAND{ROYALFLUSH, STRAIGHTFLUSH,QUADS, FULLHOUSE, FLUSH, STRAIGHT, TRIPS, TWOPAIR, ONEPAIR, HIGH};
        HAND getBestHand(std::vector<Card> cards);
    private:
        bool isRoyalFlush();
        bool isStraightFlush();
        bool isQuad();
        bool isFullHouse();
        bool isFlush();
        bool isStraight();
        bool isTrips();
        bool isTwoPair();
        bool isOnePair();
        bool isHigh();

};


#endif // HANDEVALUATOR_HPP_INCLUDED
