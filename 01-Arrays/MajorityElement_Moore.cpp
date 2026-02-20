#include <iostream>
#include <vector>

int findMajorityElement(std::vector<int> &nums)
{
    int size = nums.size();

    // frequency counter
    int freq = 0;
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    return ans;
}
int main()
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int size;
    std ::cin >> size;

    std ::vector<int> vec(size);
    for (int &val : vec)
    {
        std::cin >> val;
    }

    std ::cout << findMajorityElement(vec) << "\n";

    return 0;
}