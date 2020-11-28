#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = 0;
    bool vis[100001] = { false };
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> to(n);
        for(auto& edge:edges){
            to[edge[0]].push_back(edge[1]);
            to[edge[1]].push_back(edge[0]);
        }
        dfs(0,to,hasApple);
        return ans;
    }

    bool dfs(int from, vector<vector<int>>& to,vector<bool> hasApple){
        vis[from] = true;
        if (to[from].empty()) return hasApple[from];
        bool flag = false;
        for (auto& t : to[from]) {
            if (vis[t]) continue;
            if (dfs(t, to, hasApple)) {
                ans += 2;
                flag = true;
            }
        }
        return flag || hasApple[from];
    }
};