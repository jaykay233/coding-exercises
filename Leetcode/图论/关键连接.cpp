#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> num;
    vector<int> low;
    vector<vector<int>> G;
    int dfn =0;
    vector<vector<int>> res;
    vector<bool> vis;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        num.assign(n,0);
        low.assign(n,0);
        vis.assign(n,false);
        G.resize(n);
        for(vector<int>& connect:connections){
            int a = connect[0];
            int b = connect[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i =0;i<n;i++){
            if(!vis[i])
                dfs(i,-1);
        }
        return res;
    }


    void dfs(int u,int fa){
        if(vis[u]) return ;
        vis[u] = true;
        low[u]=num[u]=++dfn;
        for(int i =0;i<G[u].size();i++){
            int v = G[u][i];
            if(v==fa) continue;
            if(!num[v]){
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v]>num[u]) 
                    res.push_back({u,v});
            }else if(num[v]<num[u] && v!=fa){
                low[u] = min(low[u],num[v]);
            }
        }
    }
};