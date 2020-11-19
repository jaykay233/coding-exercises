#include <bits/stdc++.h>
using namespace std;
struct edge{
    int from;
    int to;
    int weight;
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n);
        for(int i =0;i<n;i++) dist[i]=INT_MAX/2;
        vector<edge> edges;
        dist[src] =0;
        for(vector<int> flight:flights){
            edges.push_back({flight[0],flight[1],flight[2]});
        }

        for(int i=0;i<=K;i++){
            vector<int> dist2(dist);
            for(auto edge:edges){
                int u = edge.from;
                int v = edge.to;
                int weight = edge.weight;
                dist2[v] = min(dist2[v],dist[u] + weight);
            }
            dist = dist2;
        }
        return dist[dst]==INT_MAX/2?-1:dist[dst];
    }
};