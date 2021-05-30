#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row+1);
        dp[0] = poured;
        for(int i=1;i<dp.size();i++){
            vector<double> dp2(dp.size());
            for(int j =0;j<dp.size();j++){
                dp2[j] += (dp[j]>1.0 ? (dp[j]-1.0)/2.0:0.0);
                if(j>0)
                    dp2[j] += (dp[j-1]>1.0? (dp[j-1]-1.0)/2.0:0.0);
            }
            dp = dp2;
        }
        return min(1.0,dp[query_glass]);
    }
};