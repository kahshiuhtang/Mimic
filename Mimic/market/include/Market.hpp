#ifndef MARKET_HPP_INCLUDED
#define MARKET_HPP_INCLUDED

#include <unordered_map>
#include <string>
#include "Stock.hpp"
class Market{
public:
    std::unordered_map<std::string, Stock> nameToStockMap;

private:

};


#endif // MARKET_HPP_INCLUDED
