#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9+7;
    int numTilings(int N) {
        vector<long> dp(N+3);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i <= N; i++){
            dp[i] = (2*(dp[i-1] % mod) % mod + dp[i-3] % mod) % mod;
        }
        return dp[N];
    }
};