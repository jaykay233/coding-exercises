#include <bits/stdc++.h>
using namespace std;

class Solution{
public:   
    int minInsertions(string s){
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(int i =0;i<n;i++) dp[i][i] = 0;
        for(int i =0;i+1<n;i++) dp[i][i+1] = (s[i]==s[i+1]?0:1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = 1 + min(dp[i][j-1],dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};