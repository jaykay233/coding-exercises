#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int asize = s1.size();
        int bsize = s2.size();
        vector<vector<int>> dp(asize + 1, vector<int>(bsize + 1, 0));
        for (int i = 1; i <= asize; i++)
            for (int j = 1; j <= bsize; j++) {
                if (s1[i - 1] == s2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return accumulate(s1.begin(),s1.end(),0) + accumulate(s2.begin(),s2.end(),0) - 2*dp[asize][bsize];
    }
};