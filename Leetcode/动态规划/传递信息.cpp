class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<int> indegree(n);
        unordered_map<int,vector<int>> m;
        for(int i =0;i<relation.size();i++){
            int from = relation[i][0];
            int to = relation[i][1];
            indegree[to] ++;
            m[to].push_back(from);
        }
        vector<vector<int>> dp(k+1,vector<int>(n));
        dp[0][0] = 1;
        for(int i =1;i<=k;i++){
            for(int j=0;j<n;j++){
                for(int k:m[j]){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        return dp[k][n-1];
    }
};