class Solution {
public:
    int tilingRectangle(int n, int m) {
        int dp[14][14];
        memset(dp,0x3f,sizeof dp);
        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==j) dp[i][j] = 1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<i;k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
        
                for(int k=1;k<j;k++){
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j-k]);
                }
                
                for(int p=1;p<=min(i,j);p++){
                    for(int k=1;k<=p;k++){
                        if(p - k <= 0 || j - p <= 0 || i - p + k <= 0 || j - p - k <= 0) continue;
                        dp[i][j] = min(dp[i][j], dp[p - k][j - p] + dp[i - p + k][j - p - k] + dp[i - p][p + k] + 2);
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};