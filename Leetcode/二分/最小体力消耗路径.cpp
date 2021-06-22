#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    bool check(vector<vector<int>>& heights,int value){
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        while(!q.empty()){
            pair<int,int> t = q.front();q.pop();
            int x = t.first;
            int y = t.second;
            if(x==m-1 && y == n-1) return true;            
            if(visit[x][y]) continue;
            visit[x][y] = true;
            for(int i =0;i<4;i++){
                int tx = x + dirs[i][0];
                int ty = y + dirs[i][1];
                if(!(tx>=0 && tx<m && ty>=0 && ty<n) || visit[tx][ty]) continue;
                if(abs(heights[x][y]-heights[tx][ty])<=value){
                    q.push(make_pair(tx,ty));
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int min_value = INT_MAX;
        int max_value = INT_MIN;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                min_value = min(min_value, heights[i][j]);
                max_value = max(max_value, heights[i][j]);
            }
        }
        int l = 0, r = max_value - min_value;
        while(l<r){
            int mid = l + r >> 1;
            if(check(heights, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};