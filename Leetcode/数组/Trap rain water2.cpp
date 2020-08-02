#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        int col = heightMap[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        for(int i =0;i<col;i++){
            q.push({heightMap[0][i],0*col+i});
            visited[0][i] = true;
            q.push({heightMap[row-1][i],(row-1)*col+i});
            visited[row-1][i] = true;
        }
        
        for(int i =0 ;i<row;i++){
            q.push({heightMap[i][0],i*col + 0});
            visited[i][0] = true;
            q.push({heightMap[i][col-1], i*col + col-1});
            visited[i][col-1] = true;
        }
        
        int maxvalue = 0;
        int ans = 0;
        while(!q.empty()){
            auto t = q.top(); q.pop();
            int height = t.first;
            int idx = t.second;
            int r = idx / col, c = idx % col;
            if(height<maxvalue){
                ans += maxvalue - height;
            }else{
                maxvalue = height;
            }
            if(r+1<row && !visited[r+1][c]){
                q.push({heightMap[r+1][c],(r+1)*col+c});
                visited[r+1][c] = true;
            }
            if(r-1>=0 && !visited[r-1][c]){
                q.push({heightMap[r-1][c],(r-1)*col+c});
                visited[r-1][c] = true;
            }
            if(c+1<col && !visited[r][c+1]){
                q.push({heightMap[r][c+1],r*col+c+1});
                visited[r][c+1] = true;
            }
            if(c-1>=0 && !visited[r][c-1]){
                q.push({heightMap[r][c-1],r*col+c-1});
                visited[r][c-1] = true;
            }
        }
        return ans;
        
    }
};