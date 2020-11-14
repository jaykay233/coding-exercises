#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n));
        for (int row = 1; row <= m; ++row)
            for (int i = 0; i < (1 << n); ++i) {
                bitset<8> bs(i);
                bool ok = true;
                for (int j = 0; j < n; ++j) {
                    if (bs[j] && seats[row-1][j] == '#' || (j < n - 1 && bs[j] && bs[j + 1])) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    dp[row][i] = -1;
                    continue;
                }
                for (int last = 0; last < (1 << n); ++last) {
                    if (dp[row - 1][last] == -1)
                        continue;
                    bitset<8> lbs(last);
                    bool ok = true;
                    for (int j = 0; j < n; ++j) {
                        if (lbs[j] && ((j > 0 && bs[j - 1]) || (j < n - 1 && bs[j + 1]))) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        dp[row][i] = max(dp[row][i], dp[row - 1][last] + (int)bs.count());
                }
            }
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i)
            ans = max(ans, dp[m][i]);
        return ans;
    }
};
