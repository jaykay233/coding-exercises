#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int,unordered_map<int,int>> edge;
        for(auto v:edges){
            int x = v[0], y = v[1], weight = v[2];
            edge[x][y] = weight;
            edge[y][x] = weight;
        }
        vector<long long> dist(n+1,INT_MAX);
        dist[n] = 0LL;
        unordered_set<int> visited;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.emplace(0,n);
        while(!minHeap.empty()){
            auto [closestDist,closestNode] = minHeap.top();minHeap.pop();
            visited.insert(closestNode);
            for(auto [nxt,weight]:edge[closestNode]){
                if(visited.count(nxt)) continue;
                if(dist[closestNode] + edge[closestNode][nxt] < dist[nxt]){
                    dist[nxt] = dist[closestNode] + edge[closestNode][nxt];
                    minHeap.emplace(dist[nxt],nxt);
                }
            }
        }
        
        vector<long long> dp(n+1,0);
        dp[n] = 1;
        vector<int> a;
        for(int i=1;i<=n;i++) a.push_back(i);
        sort(a.begin(),a.end(),[&](int x,int y){
            return dist[x] < dist[y];
        });
        for(int node:a){
            for(auto& [nxt,weight]:edge[node]){
                if(dist[node] > dist[nxt]){
                    dp[node] += dp[nxt];
                    dp[node] %= mod;
                }
            }
            if(node==1)
                break;
        }
        return dp[1] % mod;
    }
};