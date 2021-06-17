#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(n));
        int ans = 0;
        for(int row =0;row <m;row ++){
            for(int col =0;col < n;col++){
                if(grid[row][col]==1){
                    for(int col2 = col+1;col2<n;col2++){
                        if(grid[row][col2]==1){
                            ans += dp[col][col2];
                            dp[col][col2] ++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};