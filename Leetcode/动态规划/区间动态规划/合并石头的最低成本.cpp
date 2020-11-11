#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int mergeStones(vector<int>& stones,int k){
        int n = stones.size();
        if((n-1)%(k-1)!=0) return -1;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1)));
        vector<int> sum(n+1);
        for(int i=1;i<=n;i++) sum[i] =sum[i-1] + stones[i-1];
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int m=2;m<=k;m++) dp[i][j][m] = 99999;
            }
            dp[i][i][1] = 0;
        }

        for(int len=2;len<=n;len++){
            for(int i=2;i+len-1<=n;i++){
                int j = i + len-1;
                for(int m=2;m<=k;m++){
                    for(int p=i;p<j;p+=k-1){
                        dp[i][j][m] = min(dp[i][j][m],dp[i][p][1] + dp[p+1][j][m-1]);
                    }
                }
                dp[i][j][1] = dp[i][j][k] + sum[j] - sum[i-1];
            }
        }
        
        return dp[1][n][1];
    }
};