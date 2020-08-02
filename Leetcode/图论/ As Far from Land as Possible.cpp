//典型题型
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dist[110][110];
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    
    void print(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                cout<<dist[i][j];
            }
            cout<<endl;
        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        memset(dist,-1,sizeof dist);
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> t = q.front();q.pop();
            int x = t.first, y = t.second;
            for(int i =0;i<4;i++){
                int tx = x + dirs[i][0];
                int ty = y + dirs[i][1];
                if(tx>=0 && tx<grid.size() && ty>=0 && ty<grid[0].size() && dist[tx][ty]==-1){
                    dist[tx][ty] = dist[x][y] + 1;
                    q.push({tx,ty});
                }
            }
        }
        
        int max_ = 0;
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid.size();j++){
                if(dist[i][j] && dist[i][j]!=-1) max_ = max(max_,dist[i][j]);
            }
        }
        print(grid);
        
        return max_ == 0?-1 : max_;
    }
};