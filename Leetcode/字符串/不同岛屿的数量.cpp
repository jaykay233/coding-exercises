#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        int Row = grid.size(),  Col = grid[0].size();
        unordered_set<string> rec;
        vector<vector<bool>> visited(Row, vector<bool>(Col, false));
        string curPath;
        std::function<void (int, int)> dfs = [&] (int r, int c)
        {
            if (visited[r][c] == true)
                return;
            visited[r][c] = true;
            vector<pair<int,int>> nxt{{r,c+1},{r+1,c},{r,c-1},{r-1,c}};
            for (int i = 0; i < 4; i ++)
            {
                auto [nr,nc] = nxt[i];
                if (0<=nr && nr<Row && 0<=nc && nc<Col && grid[nr][nc]==1 )
                {   
                    curPath += ('1' + i);
                    dfs(nr, nc);
                }
            }
        };        
        for (int r = 0; r < Row; r ++)
        {
            for (int c = 0; c < Col; c ++)
            {
                if (grid[r][c] == 1 && visited[r][c] == false)  //起点，是岛屿，且未visit
                {
                    curPath = "0";      //全局变量！！！！！！！！！！！
                    dfs(r, c);
                    rec.insert(curPath);
                }
            }
        }
        return (int)rec.size();
    }
};
