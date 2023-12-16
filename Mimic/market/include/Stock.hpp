#ifndef STOCK_HPP_INCLUDED
#define STOCK_HPP_INCLUDED

#include <unordered_map>
#include <mutex>
#include <vector>
#include <utility>
#include <string>
class Stock
{
    using Timestamp = long long;
public:
    float getCurrentTradePrice();
    std::vector<std::pair<Timestamp, float>> getPriceHistory();
    float getOpenPrice();
    float getClosePrice();
    bool loadDataFromFile(std::string path)*;

private:
    bool isGenerated;
    std::mutex mut;
    std::vector<std::pair<Timestamp, float>>  priceHistory;
    std::vector<std::pair<Timestamp, float>>  bidHistory;
    std::vector<std::pair<Timestamp, float>>  askHistory;
};

#endif // STOCK_HPP_INCLUDED
