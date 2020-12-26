#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> suffix_sum(n);
        suffix_sum[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + stoneValue[i];
        }

        vector<int> f(n + 1);
        // 边界情况，当没有石子时，分数为 0
        // 为了代码的可读性，显式声明
        f[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int bestj = f[i + 1];
            for (int j = i + 2; j <= i + 3 && j <= n; ++j) {
                bestj = min(bestj, f[j]);
            }
            f[i] = suffix_sum[i] - bestj;
        }
        
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        if (f[0] * 2 == total) {
            return "Tie";
        }
        else {
            return f[0] * 2 > total ? "Alice" : "Bob";
        }
    }
};
