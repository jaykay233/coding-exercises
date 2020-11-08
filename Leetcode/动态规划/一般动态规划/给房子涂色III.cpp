class Solution {
public:
    const int inf = 1e8;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(target+1,inf)));
        if(houses[0]!=0) dp[0][houses[0]][1] = 0;
        else{
            for(int j=1;j<=n;j++)
                dp[0][j][1] = cost[0][j-1];
        }

        for(int i=1;i<m;i++){
            if(houses[i]==0){
                for(int j1=1;j1<=n;j1++){
                    for(int k=1;k<=target;k++){
                        for(int j2=1;j2<=n;j2++){
                            if(j1==j2) dp[i][j1][k] = min(dp[i][j1][k],dp[i-1][j2][k] + cost[i][j1-1]);
                            else dp[i][j1][k] = min(dp[i][j1][k], dp[i-1][j2][k-1] + cost[i][j1-1]);
                        }
                    }
                }
            }
            else if(houses[i]!=0){
                for(int k=1;k<=target;k++){
                    for(int j2=1;j2<=n;j2++){
                        int j1 = houses[i];
                        if(j1==j2) dp[i][j1][k] = min(dp[i][j1][k],dp[i-1][j2][k]);
                        else dp[i][j1][k] = min(dp[i][j1][k],dp[i-1][j2][k-1]);
                    }
                }
            }
        }
        int ans = 1e8;
        for(int i=1;i<=n;i++) ans = min(ans,dp[m-1][i][target]);
        return ans==1e8?-1:ans;
    }
};