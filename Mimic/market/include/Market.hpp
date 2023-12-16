#ifndef MARKET_HPP_INCLUDED
#define MARKET_HPP_INCLUDED

#include <unordered_map>
#include <string>
#include "Stock.hpp"
class Market{
    enum mode{RANDOM, LOADED};
public:
    std::unordered_map<std::string, Stock> nameToStockMap;
    bool setMode(mode m);
private:

};


#endif // MARKET_HPP_INCLUDED
