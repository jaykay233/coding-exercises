#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        int dp[n][26];
        fill(dp[0], dp[0] + n * 26, INT_MAX >> 1);
        fill(dp[0], dp[0] + 26, 0);
        
        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDistance(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDistance(k, cur);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + d0);
                    }
                }
            }
        }

        int ans = *min_element(dp[n - 1], dp[n - 1] + 26);
        return ans;
    }
};
