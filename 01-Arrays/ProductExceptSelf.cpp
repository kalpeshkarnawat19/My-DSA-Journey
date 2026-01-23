#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int> &nums)
{

    int n = nums.size();
    std::vector<int> ans(n, 1);
    int suffix = 1;

    // prefix
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // suffix
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }
    return ans;
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

    std::vector<int> result = productExceptSelf(vec);
    for (int x : result)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}