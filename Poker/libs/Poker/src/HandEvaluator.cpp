#include "HandEvaluator.hpp"
#include "Card.hpp"
#include <vector>
#include <memory>

std::unique_ptr<HandEvaluator::Hand> HandEvaluator::getBestHand(std::vector<Card> board, std::vector<Card> hand)
{
    std::unique_ptr<Hand> bestHand = std::make_unique<Hand>();
    if (isRoyalFlush(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isStraightFlush(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isQuad(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isFullHouse(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isFlush(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isStraight(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isTrips(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isTwoPair(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isOnePair(bestHand, board, hand))
    {
        return bestHand;
    }
    else if (isHigh(bestHand, board, hand))
    {
        return bestHand;
    }
    return bestHand;
}

bool HandEvaluator::isRoyalFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isStraightFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isQuad(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isFullHouse(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isStraight(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isTrips(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isTwoPair(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isOnePair(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
bool HandEvaluator::isHigh(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
}
