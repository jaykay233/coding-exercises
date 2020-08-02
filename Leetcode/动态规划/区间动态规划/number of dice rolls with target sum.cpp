#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<vector<int>> dp;
    int numRollsToTarget(int d,int f,int target){
        const int mod = 1e9+7;
        dp = vector<vector<int>>(d+1,vector<int>(target+1));
        dp[0][0] = 1;
        for(int i=1;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(j>=k){
                        dp[i][j] = dp[i][j]%mod + dp[i-1][j-k]%mod;
                        dp[i][j] %=mod;
                    }
                }
            }
        }
        return dp[d][target]%mod;
    }
};