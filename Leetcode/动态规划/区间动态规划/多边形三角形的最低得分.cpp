class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n,vector<int>(n));

        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                for(int m=i+1;m<j;m++){
                    if(dp[i][j]==0)
                        dp[i][j] = A[i]*A[j]*A[m] + dp[i][m] + dp[m][j];
                    else
                        dp[i][j] = min(dp[i][j],A[i] * A[j] * A[m] + dp[i][m] + dp[m][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};