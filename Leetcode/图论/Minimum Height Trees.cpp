#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> degree;
    unordered_map<int,unordered_set<int>> s;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return {0};
        degree = vector<int>(n,0);
        for(auto edge:edges){
            int a = edge[0], b = edge[1];
            degree[a] ++ ; degree[b] ++;
            s[a].insert(b);
            s[b].insert(a);
        }
        
        queue<int> q;
        for(int i =0;i<n;i++){
            if(degree[i] == 1) q.push(i);
        }
        while(n>2){
            int sz = q.size();
            for(int i =0;i<sz;i++){
                int t = q.front();q.pop();
                for(int n:s[t]){
                    degree[n]--;
                    s[n].erase(t);
                    if(degree[n]==1){
                        q.push(n);
                    }
                }
            }
            n-=sz;
        }
        
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());q.pop();
        }
        return res;
        
    }
};