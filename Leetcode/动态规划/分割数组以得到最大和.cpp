#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int maxSumAfterPartitioning(vector<int>& arr,int k){
        int n = arr.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i =1;i<=n;i++){
            int mmax = INT_MIN;
            for(int j =i;j>max(i-k,0);j--){
                mmax = max(mmax,arr[j-1]);
                dp[i] = max(dp[i],dp[j-1] + mmax * (i-j+1));
            }
        }
        return dp[n];    
    }
};