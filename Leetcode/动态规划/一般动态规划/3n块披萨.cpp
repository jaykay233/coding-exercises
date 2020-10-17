#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int calculate(const vector<int>& slices) {
        int n = slices.size();
        int choose = (n + 1) / 3;
        vector<vector<int>> dp(n + 1, vector<int>(choose + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= choose; ++j) {
                dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i - 1]);
            }
        }
        return dp[n][choose];
    }

    int maxSizeSlices(vector<int>& slices) {
        if(slices.empty()) return 0;
        vector<int> ans1 = vector<int>(slices.begin(),slices.end()-1);
        vector<int> ans2 = vector<int>(slices.begin()+1,slices.end());
        return max(calculate(ans1),calculate(ans2));
    }
};