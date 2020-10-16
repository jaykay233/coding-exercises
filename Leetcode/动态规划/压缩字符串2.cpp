#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        auto cal = [](int x){
            if(x==1) return 1;
            if(x<10) return 2;
            if(x<100) return 3;
            return 4;
        };
        int n = s.size();
        vector<vector<int>> f(n+1,vector<int>(k+1,INT_MAX>>1));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k && j <= i; ++j) {
                if (j > 0) {
                    f[i][j] = f[i - 1][j - 1];
                }
                int same = 0, diff = 0;
                for (int i0 = i; i0 >= 1 && diff <= j; --i0) {
                    if (s[i0 - 1] == s[i - 1]) {
                        ++same;
                        f[i][j] = min(f[i][j], f[i0 - 1][j - diff] + cal(same));
                    } else {
                        ++diff;
                    }
                }
            }
        }

        return f[n][k];
    }
};