#include "poker/hand_evaluator.hpp"
#include "poker/card.hpp"
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
// Ace->10, same suite
bool HandEvaluator::isRoyalFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    return false;
}
// Same Suite
bool HandEvaluator::isStraightFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    int countPerValue[NUM_CARD_VALUES];
    for (Card *c : allCards)
    {
        countPerValue[c->getValue()]++;
    }
    return false;
}
// Four of the same
bool HandEvaluator::isQuad(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    int countPerValue[NUM_CARD_VALUES];
    for (Card *c : allCards)
    {
        countPerValue[c->getValue()]++;
    }
    bool foundQuads = false;
    Card::Value foundQuadsValue;
    for (int i = 0; i < NUM_CARD_VALUES; i++)
    {
        if (countPerValue[i] == 4)
        {
            foundQuads = true;
            foundQuadsValue = Card::Value(i);
            break;
        }
    }
    if (foundQuads)
    {
        int nextAvailIndex = 0;
        for (Card *c : allCards)
        {
            if (c->getValue() == foundQuadsValue)
            {
                bestHand->cards[nextAvailIndex] = *c;
                nextAvailIndex += 1;
            }
        }
    }
    return false;
}
// Three and Two
bool HandEvaluator::isFullHouse(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    return false;
}
// Five from one color
bool HandEvaluator::isFlush(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    int values[NUM_CARD_SUITES];
    for (Card *c : allCards)
    {
        values[c->getSuite()]++;
    }
    bool foundFlush = false;
    Card::Suite flushSuiteFound;
    for (int i = 0; i < NUM_CARD_SUITES; i++)
    {
        if (values[i] == 5)
        {
            foundFlush = true;
            flushSuiteFound = Card::Suite(i);
            break;
        }
    }
    if (foundFlush)
    {
        int nextAvailableIndex = 0;
        for (Card *c : allCards)
        {
            if (c->getSuite() == flushSuiteFound)
            {
                bestHand->cards[nextAvailableIndex] = *c;
                nextAvailableIndex += 1;
            }
        }
        return true;
    }
    return false;
}
// Consecutive
bool HandEvaluator::isStraight(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    const int NUM_IN_A_STRAIGHT = 5;
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    int countPerValue[NUM_CARD_VALUES];
    for (Card *c : allCards)
    {
        countPerValue[c->getValue()]++;
    }
    bool foundStraight = false;
    int straightStartingIndex = -1;
    for (int i = 0; i < NUM_CARD_VALUES; i++)
    {
        if (countPerValue[i] == 1)
        {
            bool didBreakEarly = false;
            for (int numFromStartIdx = 1; numFromStartIdx < NUM_IN_A_STRAIGHT; numFromStartIdx++)
            {
                if (i + numFromStartIdx >= NUM_CARD_VALUES || countPerValue[i + numFromStartIdx] == 0)
                {
                    didBreakEarly = true;
                    break;
                }
            }
            if (!didBreakEarly)
            {
                foundStraight = true;
                straightStartingIndex = i;
                break;
            }
        }
    }
    if (foundStraight == true && straightStartingIndex != -1)
    {
        int nextAvailIdx = 0;
        for (Card *c : allCards)
        {
            if (c->getValue() >= nextAvailIdx && c->getValue() < nextAvailIdx + NUM_CARD_VALUES)
            {
                bestHand->cards[nextAvailIdx] = *c;
                nextAvailIdx += 1;
            }
        }
        return true;
    }
    return false;
}
bool HandEvaluator::isTrips(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    int values[NUM_CARD_VALUES];
    for (Card *c : allCards)
    {
        values[c->getValue()]++;
    }
    bool foundTriple = false;
    Card::Value highestValue = Card::Value(0);
    for (int i = 0; i < NUM_CARD_VALUES; i++)
    {
        if (values[i] == 3)
        {
            foundTriple = true;
            highestValue = Card::Value(i);
        }
    }
    if (foundTriple)
    {
        int nextAvailableIndex = 0;
        for (Card *c : allCards)
        {
            if (c->getValue() == highestValue)
            {
                bestHand->cards[nextAvailableIndex] = *c;
                nextAvailableIndex++;
            }
        }
    }
    return false;
}
bool HandEvaluator::isTwoPair(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    int values[NUM_CARD_VALUES];
    for (Card *c : allCards)
    {
        values[c->getValue()]++;
    }
    int foundPairs = 0;
    int nextIndexToUse = 0;
    Card::Value highestValues[2] = {Card::Value(0), Card::Value(0)};
    for (int i = 0; i < NUM_CARD_VALUES; i++)
    {
        if (values[i] >= 2)
        {
            highestValues[nextIndexToUse] = Card::Value(i);
            nextIndexToUse = (nextIndexToUse + 1) % 2;
            foundPairs += 1;
        }
    }
    if (foundPairs >= 2)
    {
        int currentCountInd1 = 0;
        int currentCountInd2 = 2;
        for (Card *c : allCards)
        {
            if (c->getValue() == highestValues[0])
            {
                bestHand->cards[currentCountInd1] = *c;
                currentCountInd1 += 1;
            }
            else if (c->getValue() == highestValues[1])
            {
                bestHand->cards[currentCountInd2] = *c;
                currentCountInd2 += 1;
            }
        }
        return true;
    }
    return false;
}
bool HandEvaluator::isOnePair(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    int values[NUM_CARD_VALUES];
    for (Card *c : allCards)
    {
        values[c->getValue()]++;
    }
    bool foundPair = true;
    Card::Value highestValue;
    for (int i = 0; i < NUM_CARD_VALUES; i++)
    {
        if (values[i] >= 2)
        {
            highestValue = Card::Value(i);
            foundPair = true;
        }
    }
    if (foundPair)
    {
        int currentInd = 0;
        for (Card *c : allCards)
        {
            if (currentInd == 2)
                break;
            if (c->getValue() == highestValue)
                bestHand->cards[currentInd] = *c;
            currentInd++;
        }
        return true;
    }
    return false;
}
bool HandEvaluator::isHigh(const std::unique_ptr<Hand> &bestHand, std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards = combineBoardAndHand(board, hand);
    Card::Value highestFoundCard = Card::Value::TWO;
    Card *bestCard;
    for (Card *c : allCards)
    {
        if (c->getValue() > highestFoundCard)
        {
            highestFoundCard = c->getValue();
            bestCard = c;
        }
    }
    bestHand->cards[0] = *bestCard;
    bestHand->type = HandType::HIGH;
    return true;
}
std::vector<Card *> HandEvaluator::combineBoardAndHand(std::vector<Card> board, std::vector<Card> hand)
{
    std::vector<Card *> allCards;
    for (Card c : board)
    {
        allCards.push_back(&c);
    }
    for (Card c : hand)
    {
        allCards.push_back(&c);
    }
    return allCards;
}
