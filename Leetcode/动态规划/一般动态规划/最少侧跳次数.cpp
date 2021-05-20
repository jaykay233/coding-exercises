class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n,vector<int>(3,1e9));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
        for(int i=1;i<dp.size();i++){
            for(int j =0;j<3;j++){
                if(obstacles[i]==j+1) continue;
                dp[i][j] = dp[i-1][j];
            }
            for(int j =0;j<3;j++){
                if(obstacles[i]==j+1) continue;
                int a = (j + 1) % 3;
                int b = (j + 2) % 3;
                int side = min(dp[i][a],dp[i][b]) + 1;
                dp[i][j] = min(dp[i][j],side);
            }
        }
        return *min_element(dp.back().begin(),dp.back().end());
    }
};