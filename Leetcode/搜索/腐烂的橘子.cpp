#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        bool has_rot=false;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1){
                    has_rot = true;
                }
            }
        }
        if(q.empty() && has_rot) return -1;
        if(q.empty() && !has_rot) return 0;
        int level =0 ;
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                pair<int,int> p = q.front();q.pop();
                for(auto d:dirs){
                    int x = p.first + d[0];
                    int y = p.second + d[1];
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(grid[x][y]==0 || grid[x][y]==2) continue;
                        grid[x][y] = 2;
                        q.push(make_pair(x,y));
                    }
                }
            }
            level++;
        }
        
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return level-1;
    }
};