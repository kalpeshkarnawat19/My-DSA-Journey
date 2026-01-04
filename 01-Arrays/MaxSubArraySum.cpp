#include <iostream>
#include <vector>

 int maxSubArray(const std::vector<int> & nums)
    {
        int currentSum = 0;
        int maxSum = INT32_MIN;
        for (int val : nums)
        {
            currentSum += val;
            maxSum = std::max(maxSum, currentSum);
            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }
        return maxSum;
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

    std::cout << maxSubArray(vec) << "\n";
    return 0;
}