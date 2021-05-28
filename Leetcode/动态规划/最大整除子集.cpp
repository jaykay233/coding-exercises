#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        int res = 0;
        int max_res = 1;
        vector<int> pre(n,-1);
        for(int i =1;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i] % nums[j]==0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if(dp[i]>max_res){
                max_res = dp[i];
                res = i;
            }
        }
        vector<int> ans;
        while(res!=-1){
            ans.push_back(nums[res]);
            res = pre[res];
        }
        return ans;
    }
};