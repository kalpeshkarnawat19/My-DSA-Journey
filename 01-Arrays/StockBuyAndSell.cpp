#include <iostream>
#include <vector>

int MaxProfit(const std::vector<int> &prices)
{
    int maxProfit = 0;
    int bestBuy = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > bestBuy)
        {
            maxProfit = std::max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = std::min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main()
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int size;
    if (!(std::cin >> size))
        return 0;

    std::vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> vec[i];
    }

    std::cout << MaxProfit(vec) << "\n";
    return 0;
}