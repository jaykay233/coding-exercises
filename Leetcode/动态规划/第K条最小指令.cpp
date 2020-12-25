#include <bits/stdc++.h>
using namespace std;

//通过组合数求第K条最短路径

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int h = destination[1];
        int v = destination[0];
        
        vector<vector<int>> comb(h + v, vector<int>(h));
        comb[0][0] = 1;
        for (int i = 1; i < h + v; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i && j < h; ++j) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
        
        string ans;
        for (int i = 0, imax = h + v; i < imax; ++i) {
            if (h > 0) {
                int o = comb[h + v - 1][h - 1];
                if (k > o) {
                    ans += 'V';
                    --v;
                    k -= o;
                }
                else {
                    ans += 'H';
                    --h;
                }
            }
            else {
                ans += 'V';
                --v;
            }
        }
        return ans;
    }
};
