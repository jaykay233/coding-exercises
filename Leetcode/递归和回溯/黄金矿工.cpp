class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    int res=0;
    void backtracing(vector<vector<int>>&grid,int i,int j,int sum){
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]==0){
                continue;
            }
            int temp=grid[x][y];
            grid[x][y]=0;
            backtracing(grid,x,y,sum+temp);
            grid[x][y]=temp;
        }
        res=max(res,sum);
        return ;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    continue;
                }
                int T=grid[i][j];
                grid[i][j]=0;
                backtracing(grid,i,j,T);
                grid[i][j]=T;
            }
        }
        return res;
    }
};
