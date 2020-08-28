#include <bits/stdc++.h>
using namespace std;
class Solution{
public: 
    int maxSumAfterPartitioning(vector<int>& A,int K){
        int n = A.size();
        vector<int> dp(n,0);
        for(int i =0;i<A.size();i++){
            int curmax = 0;
            for(int j =1;j<=K && i-j+1>=0;j++){
                curmax = max(curmax,A[i-j+1]);
                dp[i] = max(dp[i],(i>=K?dp[i-j]:0)+curmax*j);
            }
        }
        return dp[n-1];
    }
};