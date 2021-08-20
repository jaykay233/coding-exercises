#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int searchInsert(vector<int>& nums,int target){
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + right >> 1;
            if(nums[mid] > target)
                right = mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] == target)
                return mid;
        }
        return left;
    }
};