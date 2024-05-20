//https://www.geeksforgeeks.org/stock-buy-sell/
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <array>
//#include <tuple>
#include <span>

uint64_t
max_profit(std::span<uint64_t> price, size_t start, size_t end)
{
    uint64_t profit {0};
//printf("%lu %lu\n", start, end);
    for (size_t buy_pos = start; buy_pos < end; ++buy_pos)
    {
        for (size_t sell_pos = buy_pos + 1; sell_pos <= end; ++sell_pos)
        {
            if (price[sell_pos] > price[buy_pos]) {
                uint64_t the_profit = (price[sell_pos] - price[buy_pos]) +
                    max_profit(price, start, (buy_pos > start)? (buy_pos - 1) : start)+
                    max_profit(price, (sell_pos < end)? (sell_pos + 1):end, end);
                if (the_profit > profit) {
                    //printf("%lu %lu, profit=%lu\n", buy_pos, sell_pos, the_profit);
                }
                profit = std::max(profit, the_profit);
                //printf("%lu %lu, profit=%lu\n", start, end, profit);
            }
        }
    }

    return profit;
}

uint64_t
method1_check_every_day(std::span<uint64_t> a, size_t size)
{
    uint64_t profit {0};

    profit = max_profit(a, 0, size - 1);

    return profit;
}

void init(std::span<uint64_t> as, size_t size)
{
    for (auto& a : as) {
        a = rand() % size;
    }
}


int main()
{
    const size_t SIZE = 20;
    std::array<uint64_t,SIZE> as;

    init(as, SIZE);
    for (auto& a : as) {
        printf("%lu,", a);
    }
    puts("");

    uint64_t profit = method1_check_every_day(as, SIZE);
    printf("profit=%lu\n", profit);

    return 0;
}
