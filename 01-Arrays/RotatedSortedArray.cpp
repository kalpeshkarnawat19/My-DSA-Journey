#include <iostream>
#include <vector>


int search(std::vector<int>& nums, int target)
{
    int st =0;
    int end = nums.size()-1;
    while(st<=end)
    {
        int mid = st+(end-st)/2;
        if(nums[mid]==target)
        return mid;
        if(nums[st]<= nums[mid])
        {
            if(nums[st]<=target && target<nums[mid])
            end = mid-1;
            else
            st = mid+1;
        }
        else
        {
            if(nums[mid]<target && target<=nums[end])
            st = mid+1;
            else
            end = mid-1;
        }
    }
    return -1;
}

int main()
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int target;
    int size;
    if (!(std::cin >> size))
    return 0;
    
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> vec[i];
    }
    std::cin>>target;

    std::cout << search(vec,target) << "\n";
    return 0;
}