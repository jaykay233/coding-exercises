//这个问题推广到k枚鸡蛋是一样的
//https://leetcode-cn.com/problems/egg-drop-with-2-eggs-and-n-floors/solution/dong-tai-gui-hua-shu-xue-tui-dao-by-tang-1zz1/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(2,vector<int>(n+1,INT_MAX));
        dp[0][0] = dp[1][0] = 0;
        for(int j = 1;j<=n;j++) {
            dp[0][j] = j;
        }
        for(int j =1;j<=n;j++){
            for(int k =1;k<=j;k++){
                dp[1][j] = min(dp[1][j],max(dp[0][k-1] + 1, dp[1][j-k] + 1));
            }
        }
        return dp[1][n];
    }
};