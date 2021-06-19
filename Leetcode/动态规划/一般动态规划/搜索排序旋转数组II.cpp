#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid;
        while(l<=r){
            while(l<r && nums[l] == nums[l+1]) l++;
            while(l<r && nums[r] == nums[r-1]) r--;
            mid = l + r >> 1;
            if(nums[mid] == target) return true;
            if(nums[mid] >= nums[0]){
                if(nums[mid] > target && target >= nums[0]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums.back()){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};