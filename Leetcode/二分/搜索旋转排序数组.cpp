#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if(nums.empty()) return -1;
        if(nums.size()==1) return nums[0] == target?0:-1;
        while(l<=r){
            int mid = l + r >> 1;
            if(target == nums[mid]) return mid;
            if(nums[mid] >= nums[0]){
                if(nums[0] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }else{
                if(nums[mid] < target && target <= nums.back()) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};