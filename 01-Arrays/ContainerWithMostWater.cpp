#include <iostream>
#include <vector>

int MaxArea(const std::vector<int> &height)
{
    int maxWater = 0;
    int lp = 0, rp = height.size() - 1;
    while (lp < rp)
    {
        int w = rp - lp;
        int ht = std::min(height[lp], height[rp]);
        int currentWater = w * ht;
        maxWater = std::max(maxWater, currentWater);

        height[lp] < height[rp] ? lp++ : rp--;
    }

    return maxWater;
}

int main()
{
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

    std::cout << MaxArea(vec) << "\n";
    return 0;
}