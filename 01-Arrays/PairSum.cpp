#include <iostream>
#include <vector>

void findPairSum(const std::vector<int> &vec, int target) // using constant as we just want to read the array
{
    int start = 0;
    int end = vec.size() - 1;
    while (start < end)
    {
        int sum = vec[start] + vec[end];
        if (sum == target) // FOUND
        {
            std::cout << start << " " << end;
            return;
        }

        else if (sum < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    std ::cout << "No pair found\n";
}
int main()
{
    // Fast I/0
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int target = 9;
    int size;
    std ::cin >> size;

    std ::vector<int> vec(size);
    for (int &val : vec)
    {
        std::cin >> val;
    }

    findPairSum(vec, target);

    return 0;
}