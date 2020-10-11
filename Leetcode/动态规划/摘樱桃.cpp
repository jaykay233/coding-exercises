class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N,vector<int>(N,INT_MIN/2));
        dp[0][0] = grid[0][0];
        for(int t=1;t<2*N-1;t++){
            vector<vector<int>> dp2(N,vector<int>(N,INT_MIN/2));
            for(int i=max(0,t-(N-1));i<min(N-1,t)+1;i++){
                for(int j =max(0,t-(N-1));j<min(N-1,t)+1;j++ ){
                    if(grid[i][t-i] ==-1 || grid[j][t-j]==-1)
                        continue; 
                    int val = grid[i][t-i];
                    if(i!=j) val+=grid[j][t-j];
                    if(i-1>=0 && j-1>=0) dp2[i][j] = max(dp[i-1][j-1] + val,dp2[i][j]);
                    if(i-1>=0 && j>=0) dp2[i][j] = max(dp[i-1][j] + val,dp2[i][j]);
                    if(i>=0 && j-1>=0) dp2[i][j] = max(dp[i][j-1] + val,dp2[i][j]);
                    if(i>=0 && j>=0) dp2[i][j] = max(dp[i][j] + val,dp2[i][j]);
                }
            }
            dp = dp2;
        }
        return max(0,dp[N-1][N-1]);
    }
};


