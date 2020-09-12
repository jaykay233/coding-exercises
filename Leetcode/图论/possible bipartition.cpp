#include <bits/stdc++.h>
using namespace std;
class Solution{
public: 
    vector<int> color;
    unordered_map<int,vector<int>> m;
    bool possibleBipartition(int N,vector<vector<int>>& dislikes){
        color = vector<int>(N+1,-1);
        for(int i=0;i<dislikes.size();i++){
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            m[a].push_back(b);
            m[b].push_back(a);
        }
        for(int i=1;i<=N;i++){
            if(color[i]==-1 && !dfs(i,0)) return false;
        }
        return true;
    }

    bool dfs(int node,int c){
        if(color[node]==-1) return color[node] == c;
        color[node] = c;
        for(int nei:m[node]){
            if(!dfs(nei,c^1)) return false;
        }
        return true;
    }
};