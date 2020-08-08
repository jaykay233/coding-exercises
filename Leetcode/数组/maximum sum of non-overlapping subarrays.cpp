#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums,int k){
        int n = nums.size(),mx=INT_MIN;
        vector<int> sums{0},left(n,0),right(n,n-k);
        for(int i =0;i<nums.size();i++) sums.push_back(sums.back() + nums[i]);
        for(int i=k,total=sums[k]-sums[0];i<n;i++){
            if(sums[i+1] - sums[i+1-k]){
                left[i] = i+1-k;
                total = sums[i+1] - sums[i+1-k];
            }
            else left[i] = left[i-1];
        }

        for(int i=n-k-1,total = sums[n]-sums[n-k];i>=0;i--){
            if(sums[i+k] - sums[i] >= total){
                right[i] = i;
                total = sums[i+k] - sums[i];
            }
            else right[i] = right[i+1];
        }
        vector<int> res;

        for(int i=k;i<=n-2*k;i++){
            int l = left[i-1], r = right[i+k];
            int total = sums[i+k] - sums[i] + sums[l + k]-sums[l] + sums[r+k]-sums[r];
            if(total>mx){
                mx=total;
                res = {l,i,r};
            }
        }
        return res;
    }
};