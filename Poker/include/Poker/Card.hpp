#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED
#include <string>
class Card
{
public:
    enum Suite
    {
        HEART,
        SPADE,
        DIAMOND,
        CLUB
    };
    enum Value
    {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };
    Suite getSuite();
    Value getValue();
    Card(Suite s, Value v);
    Card();
    std::string getSuiteString();
    std::string getValueString();

private:
    Suite m_Suite;
    Value m_Value;
};

#endif // CARD_HPP_INCLUDED
