#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int small = INT_MAX, mid = INT_MAX;
        for(int i =0;i<n;i++){
            if(nums[i] > mid) return true;
            else if(nums[i] <= small){
                small = nums[i];
            }else if(nums[i] < mid){
                mid = nums[i];
            }
        }
        return false;
    }
};