#include <iostream>
#include <vector>

int singleElement(std::vector<int> &nums)
{
    // EDGE CASES handled
    if (nums.size() == 1)
        return nums[0]; // Array only has one element
    if (nums[0] != nums[1])
        return nums[0]; // Single element is at the very beginning
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1]; // Single element is at the very end

    int st = 1;
    int end = nums.size() - 2;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            return nums[mid];

        if (mid % 2 == 0) // even
        {
            if (nums[mid - 1] == nums[mid])
                end = mid - 1;
            else
                st = mid + 1;
        }
        else // odd
        {
            if (nums[mid - 1] == nums[mid])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
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
    std::cout << singleElement(vec) << "\n";
    return 0;
}