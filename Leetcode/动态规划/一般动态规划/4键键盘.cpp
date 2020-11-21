#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N+1);
        dp[0]=0;
        for(int i=1;i<=N;i++){
            dp[i] = dp[i-1] + 1;
            for(int j =1;j<=i;j++){
                dp[i] = max(dp[i],dp[j]*(i-j-1));
            }
        }
        return dp[N];
    }

    // dp[2] copy paste output 
};