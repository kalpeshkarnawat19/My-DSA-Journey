#include <iostream>
#include <vector>

// Marked as 'const' because we are only reading the vector
int findSingleNumber(const std::vector<int> &nums)
{
    int ans = 0;
    for (int val : nums)
    {
        ans ^= val; // Bitwise XOR
    }
    return ans;
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

    std::cout << findSingleNumber(vec) << "\n";
    return 0;
}