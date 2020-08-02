#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool blue[110][110];
    bool red[110][110];
    int dist[110][2];
    void bfs(int n){
        bool ok1 = false;
        bool ok2 = false;
        for(int i =0;i<n;i++){
            if(red[0][i]) {ok1 = true;break;}
        }
        for(int i =0;i<n;i++){
            if(blue[0][i]) {ok2 = true;break;}
        }
        queue<pair<int,int>> q;
        if(ok1) {
            dist[0][0] = 0;
            q.push({0,0});
        }
        if(ok2){
            dist[0][1] = 0;
            q.push({0,1});
        }
        if(q.empty()) return;
        while(!q.empty()){
            auto t = q.front();q.pop();
            int x = t.first, y = t.second;
            if(y==0){
                for(int i =0;i<n;i++){
                    if(!red[x][i]) continue;
                    if(dist[i][!y] > dist[x][y] + 1){
                        dist[i][!y] = dist[x][y] + 1;
                        q.push({i,!y});
                    }
                }
            }
            else if(y==1){
                for(int i=0;i<n;i++){
                    if(!blue[x][i]) continue;
                    if(dist[i][!y] > dist[x][y] + 1){
                        dist[i][!y] = dist[x][y] + 1;
                        q.push({i,!y});
                    }
                }
            }
        }
    }   
    
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        memset(blue,false,sizeof blue);
        memset(red,false,sizeof red);
        memset(dist,0x3f,sizeof dist);
        
        for(vector<int> v:red_edges){
            int a= v[0], b = v[1];
            red[a][b]  = true;
        }
        for(vector<int> v:blue_edges){
            int a= v[0],b= v[1];
            blue[a][b]  = true;
        }
        
        bfs(n);
        vector<int> res;
        for(int i =0;i<n;i++){
            int v = min(dist[i][0], dist[i][1]);
            if(i==0) v = 0;
            if(v>0x3f3f3f3f/2) res.push_back(-1);
            else res.push_back(v);
        }
        return res;
    }
};