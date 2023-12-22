#ifndef HANDEVALUATOR_HPP_INCLUDED
#define HANDEVALUATOR_HPP_INCLUDED
#include "Card.hpp"
#include <vector>
#include <memory>
class HandEvaluator
{
public:
    enum HandType
    {
        ROYALFLUSH,
        STRAIGHTFLUSH,
        QUADS,
        FULLHOUSE,
        FLUSH,
        STRAIGHT,
        TRIPS,
        TWOPAIR,
        ONEPAIR,
        HIGH
    };
    struct Hand
    {
        HandType type;
        Card cards[5];
        Hand(){};
    };
    std::unique_ptr<HandEvaluator::Hand> getBestHand(std::vector<Card> board, std::vector<Card> hand);

private:
    bool isRoyalFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isStraightFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isQuad(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isFullHouse(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isStraight(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isTrips(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isTwoPair(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isOnePair(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
    bool isHigh(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand);
};

#endif // HANDEVALUATOR_HPP_INCLUDED
