#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, int> mp;
        int n = A.size();
        // for (int i = n - 1; i >= 0; i --) mp[A[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int target = 2 * A[i] - A[j];
                if (mp.count(target)) dp[i][j] = dp[mp[target]][i] + 1;
                ans = max(ans, dp[i][j]);
            }
            mp[A[i]] = i;
        }
        return ans;
    }
};
