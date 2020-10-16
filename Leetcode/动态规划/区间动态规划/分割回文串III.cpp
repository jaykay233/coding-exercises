class Solution {
public:
    int palindromePartition(string& s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n));
        for (int span = 2; span <= n; ++span) {
            for (int i = 0; i <= n - span; ++i) {
                int j = i + span - 1;
                cost[i][j] = cost[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
            }
        }

        vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(k, i); ++j) {
                if (j == 1) {
                    f[i][j] = cost[0][i - 1];
                }
                else {
                    for (int i0 = j - 1; i0 < i; ++i0) {
                        f[i][j] = min(f[i][j], f[i0][j - 1] + cost[i0][i - 1]);
                    }
                }
            }
        }
        
        return f[n][k];
    }
};
