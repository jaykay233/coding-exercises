#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> graph;
    map<int,int> color;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(n+1);
        for(int i =1;i<=n;i++)
            graph[i] = {};
        
        for(vector<int> edge:dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int node=1;node<=n;node++){
            if(!color.count(node) && !dfs(node,0))
                return false;
        }
        return true;
    }

    bool dfs(int node, int c){
        if(color.count(node))
            return color[node] == c;
        color[node] = c;
        for(int nei:graph[node]){
            if(!dfs(nei,c^1)) return false;
        }
        return true;
    }
};