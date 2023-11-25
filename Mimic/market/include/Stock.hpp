#ifndef STOCK_HPP_INCLUDED
#define STOCK_HPP_INCLUDED
#include <unordered_map>
#include <mutex>
class Stock
{
    using Timestamp = long long;
public:
    float getCurrentTradePrice();
    std::unordered_map<Timestamp, float> getPriceHistory();
    float getOpenPrice();
    float getClosePrice();

private:
    bool isGenerated;
    std::mutex mut;
    std::unordered_map<Timestamp, float> priceHistory;
    std::unordered_map<Timestamp, float> bidHistory;
    std::unordered_map<Timestamp, float> askHistory;
};

#endif // STOCK_HPP_INCLUDED
