#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l<r){
            int m = l + r >> 1;
            if(nums[m] >= nums[0]){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return min(nums[l],nums.front());
    }
};