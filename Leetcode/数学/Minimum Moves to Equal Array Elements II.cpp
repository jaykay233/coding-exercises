#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
        int avg = nums[nums.size()/2];
        int ans =0 ;
        for(int x:nums){
            ans+=abs(x-avg);
        }
        return ans;
    }
};