class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        int dir = 0;
        int i = 0 , j = 0;
        int res = 1;
        vector<int> ans = {matrix[0][0]};
        visit[0][0] = true;
        while(res < m * n){
            // cout<<i<<" "<<j<<endl;
            int x = i + dirs[dir][0];
            int y = j + dirs[dir][1];
            if(x>=0 && x<m && y>=0 && y<n && !visit[x][y]){
                res ++;
                i += dirs[dir][0];
                j += dirs[dir][1];
                ans.push_back(matrix[i][j]);
                visit[x][y] = true;
            }else{
                dir = (dir + 1) % 4;
            }
        }
        return ans;
    }
};