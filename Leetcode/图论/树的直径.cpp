//两次dfs/bfs
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
        int maxnode = 0;
        for(auto edge:edges){
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
            maxnode = max(maxnode,edge[0]);
            maxnode = max(maxnode,edge[1]);
        }
        vector<int> visited(maxnode+1,false);

        queue<pair<int,int>> q;
        q.push({0,0});
        int res=0 ;
        int n1 = 0;
        while(!q.empty()){
            auto t = q.front();q.pop();
            if(visited[t.first]) continue;
            visited[t.first] = true;
            if(t.second > res){
                res = t.second;
                n1 = t.first;
            }
            for(int x:m[t.first]){
                if(!visited[x])
                    q.push({x,t.second + 1});
            }
        }

        // cout<<n1<<endl;

        while(!q.empty()) q.pop();

        visited=vector<int>(maxnode+1,false);
        q.push({n1,0});
        while(!q.empty()){
            auto t = q.front();q.pop();
            if(visited[t.first]) continue;
            visited[t.first] = true;
            if(t.second>res){
                res = t.second;
                n1 = t.first;
            }
            for(int x:m[t.first]){
                if(!visited[x])
                    q.push({x,t.second+1});
            }
        }
        return res;
    }  
};

//树形dp