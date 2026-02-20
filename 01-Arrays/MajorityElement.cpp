#include <iostream>
#include <vector>
#include <algorithm>

int findMajorityElement( std::vector<int> &nums)
{
    int size = nums.size();

    //Sorting
    std::sort(nums.begin(),nums.end());

    //frequency counter
    int freq = 1;
    int ans = nums[0];

    for(int i = 1; i<size; i++)
    {
        if(nums[i] == nums[i-1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }
        if(freq > size/2)
        {
            return ans;
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

    std :: cout << findMajorityElement(vec) << "\n";

    return 0;

}