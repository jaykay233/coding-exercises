class Solution {
public:
    int area = 0, flag = 1; // area 深搜的空间面积 flag = 1 不为与走廊相邻空间
    int largestArea(vector<string>& grid) {
        int res = 0, temp = 0; // res 有效最大值
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[0].size(); j++) {
                 if (grid[i][j] != '6' && grid[i][j] != '0') {
                     area = 0, flag = 1; // 初始化
                     dfs(grid, grid[i][j], i, j); // 深搜
                     if (flag) res = max(res, area); // 取最大值
                 }
            }
        return res;
    }

    void dfs(vector<string> &grid, char visited, int x, int y) { // 深搜
        grid[x][y] = '6';  
        area++;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || b < 0 || a >= grid.size() || b >= grid[0].size() || grid[a][b] == '0') 
                flag = 0;  
            if (a >= 0 && b >= 0 && a < grid.size() && b < grid[0].size() && grid[a][b] == visited ) 
                dfs(grid, grid[a][b], a, b); 
        }
    }
};
