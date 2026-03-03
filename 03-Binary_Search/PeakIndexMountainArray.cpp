#include <iostream>
#include <vector>


int peakIndexInMountainArray(std::vector<int>& nums)
{
    int st = 1;
    int end = nums.size()-2;
    while(st<=end)
    {
        int mid = st + (end-st)/2;
        if(nums[mid] > nums[mid-1] && nums[mid]>nums[mid+1]) // Peak Found
        return mid;
        else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1])  //Mid value in on the increasing slope
        st = mid+1;
        else // mid value is on the decreasing slope
        end = mid-1;
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

    std::cout << peakIndexInMountainArray(vec) << "\n";
    return 0;
}