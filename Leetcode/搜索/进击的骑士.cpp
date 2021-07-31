#include <bits/stdc++.h>
using namespace std;
//bfs镜像对称 + 剪枝
class Solution 
{
public:
    int minKnightMoves(int x, int y) 
    {
        if (x == 0 && y == 0)
            return 0;
        x = abs(x);     //都是关于（0,0）对称
        y = abs(y);
        queue<pair<int,int>> Q;
        set<pair<int,int>> visited;
        Q.push({0, 0});
        visited.insert({0, 0});
        int step = 0;
        while(true)
        {
            int cur_len = Q.size();
            step ++;
            while(cur_len --)
            {
                auto [x0, y0] = Q.front();  Q.pop();
                for (auto & [dx, dy] : vector<pair<int,int>>{{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}})
                {
                    int nx = x0 + dx;
                    int ny = y0 + dy;
                    if (visited.find({nx,ny}) == visited.end())
                    {
                        if (-5 <= nx && nx <= x + 5 && -5 <= ny && ny <= y + 5)
                        {
                            if (x == nx && y == ny)
                                return step;
                            Q.push({nx, ny});
                            visited.insert({nx, ny});
                        }
                    }
                }
            }
        }
        return 0;
    }
};
