//dp[i][j],前i枚硬币，j个向上的概率
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n+1,vector<double>(target+1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                dp[i][j] = dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1 - prob[i - 1]);
            }
        }
        return dp[n][target];
    }
};