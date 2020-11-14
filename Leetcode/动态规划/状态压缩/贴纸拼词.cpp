#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    vector<vector<int>> cnt;
    vector<vector<int>> can;
    int n;
    int m;
    const int INF = 51;
    int minStickers(vector<string>& stickers, string target) {
        n = stickers.size();
        m = target.size();
        dp=vector<int>(1<<15,INF);
        cnt =vector<vector<int>>(n,vector<int>(26));
        can = vector<vector<int>>(26);
        for(int i =0;i<stickers.size();i++){
            for(int j =0;j<stickers[i].size();j++){
                int d = stickers[i][j] - 'a';
                cnt[i][d]++;
                if(can[d].empty() || can[d].back()!=i)
                    can[d].push_back(i);
            }
        }

        dp[0] = 0;
        for (int i = 0; i < (1 << m) - 1; ++i) {
            if (dp[i] == INF)
                continue;
            int d=0;
            for (int j = 0; j < m; ++j) {
                if (!(i & (1 << j))) {
                    d = j;
                    break;
                }
            }
            d = target[d] - 'a';
            for (int k : can[d]) {
                int nxt = i;
                vector<int> left(cnt[k]);
                for (int j = 0; j < m; ++j) {
                    if (nxt & (1 << j))
                        continue;
                    if (left[target[j] - 'a'] > 0) {
                        nxt += (1 << j);
                        left[target[j] - 'a']--;
                    }
                }
                dp[nxt] = min(dp[nxt], dp[i] + 1);
            }
        }
        return dp[(1<<m)-1]==INF?-1:dp[(1<<m)-1];
    }
};