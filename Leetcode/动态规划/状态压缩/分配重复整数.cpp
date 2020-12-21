#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> cache;
        for (int x: nums) {
            cache[x]++;
        }
        vector<int> cnt;
        for (auto& kv: cache) {
            cnt.push_back(kv.second);
        }
        
        int n = cnt.size(), m = quantity.size();
        vector<int> sum(1 << m, 0);
        for (int i = 1; i < (1 << m); i++) {
            for (int j = 0; j < m; j++) {
                if ((i & (1 << j)) != 0) {
                    int left = i - (1 << j);
                    sum[i] = sum[left] + quantity[j];
                    break;
                }
            }
        }
        
        vector<vector<bool>> dp(n, vector<bool>(1 << m, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                if (i > 0 && dp[i-1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                for (int s = j; s != 0; s = ((s - 1) & j)) {  
                    int prev = j - s;  
                    bool last = (i == 0) ? (prev == 0): dp[i-1][prev];  
                    bool need = sum[s] <= cnt[i]; 
                    if (last && need) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[n-1][(1<<m)-1];
    }
};
