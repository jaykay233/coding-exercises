#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    const int mod = 1e9+7;
    int profitableSchemes(int G,int P,vector<int>& group,vector<int>& profit){
        int N = profit.size();
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(G+1,vector<int>(P+1)));
        for(int i =0;i<=N;i++){
            for(int j=0;j<=G;j++){
                dp[i][j][0] = 1;
            }
        }

        for(int i=1;i<=N;i++){
            for(int j=1;j<=G;j++){
                for(int k=0;k<=P;k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j>=group[i-1]){
                        int nk = max(k-profit[i-1],0);
                        dp[i][j][k] += dp[i-1][j-group[i-1]][nk];
                    }
                    dp[i][j][k] %= mod;
                }
            }
        }
        return dp[N][G][P];
    }
};