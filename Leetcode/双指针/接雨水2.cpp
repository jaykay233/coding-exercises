//多侧最大中取最小
struct node{
    int x;
    int y;
    int h;
    node(int x,int y,int h){
        this->x = x;
        this->y = y;
        this->h = h;
    }
};

struct cmp{
    bool operator()(const node& a,const node& b){
        return a.h > b.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<node,vector<node>,cmp> q;
        for(int i=0;i<m;i++) {
            q.push(node(i,0,heightMap[i][0]));
            q.push(node(i,n-1,heightMap[i][n-1]));
        }
        for(int j=0;j<n;j++){
            q.push(node(0,j,heightMap[0][j]));
            q.push(node(m-1,j,heightMap[m-1][j]));
        }
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int heightMax = INT_MIN;
        int ans = 0;
        while(!q.empty()){
            node nd = q.top();q.pop();
            int x = nd.x;
            int y = nd.y;
            int h = nd.h;
            if(visited[x][y]) continue;
            visited[x][y] = true;
            heightMax = max(heightMax,h);
            ans += heightMax - h;
            for(int i =0;i<dirs.size();i++){
                int tx = x + dirs[i][0];
                int ty = y + dirs[i][1];
                if(!(tx>=0 && tx<m && ty>=0 && ty<n) || visited[tx][ty]) continue;
                q.push(node(tx,ty,heightMap[tx][ty]));
            }
        }
        return ans;
    }
};