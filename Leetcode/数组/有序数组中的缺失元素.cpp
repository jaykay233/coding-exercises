#include <bits/stdc++.h>
using namespace std;

class Solution{
    int missing(int idx,vector<int>& nums){
        return nums[idx] - nums[0] - idx;
    }

    int missingElement(vector<int>& nums,int k){
        int n = nums.size();
        if(k>missing(n-1,nums)){
            return nums[n-1] + k - missing(n-1,nums);
        }
        int l = 0, r = n - 1, pivot;
        while(l<r){
            pivot = l + (r-l)/2;
            if(missing(pivot, nums) < k) l = pivot + 1;
            else r = pivot;
        }
        return nums[l-1] + k - missing(l-1,nums);
    }
};  