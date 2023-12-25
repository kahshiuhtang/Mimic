#include "poker/card.hpp"
#include <stdlib.h>
Card::Card()
{
    m_Suite = Suite(rand() % 5);
    m_Value = Value(rand() % 14);
}
Card::Card(Suite s, Value v)
{
    m_Suite = s;
    m_Value = v;
}
Card::Suite Card::getSuite()
{
    return m_Suite;
}
Card::Value Card::getValue()
{
    return m_Value;
}
std::string Card::getSuiteString()
{
    switch (m_Suite)
    {
    case HEART:
        return "HEART";
    case SPADE:
        return "SPADE";
    case CLUB:
        return "CLUBS";
    case DIAMOND:
        return "DIAMOND";
    }
    return "";
}

std::string Card::getValueString()
{
    switch (m_Value)
    {
    case ACE:
        return "ACE";
    case KING:
        return "KING";
    case TWO:
        return "TWO";
    case THREE:
        return "THREE";
    case FOUR:
        return "FOUR";
    case FIVE:
        return "FIVE";
    case SIX:
        return "SIX";
    case SEVEN:
        return "SEVEN";
    case EIGHT:
        return "EIGHT";
    case NINE:
        return "NINE";
    case TEN:
        return "TEN";
    case JACK:
        return "JACK";
    case QUEEN:
        return "QUEEN";
    }
    return "";
}
