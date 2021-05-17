#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    int maxSumAfterOperation(vector<int>& nums){
        int n = nums.size();
        int dp[n][2];memset(dp,0,sizeof dp);
        dp[0][0] = nums[0];
        dp[0][1] = nums[0] * nums[0];
        int res = dp[0][1];
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0]<=0?nums[i]:dp[i-1][0]+nums[i];
            dp[i][1] = max(dp[i-1][0]+nums[i]*nums[i],max(nums[i]*nums[i],dp[i-1][1] + nums[i]));
            res = max(res,dp[i][1]);
        }
        return res;
    }
};