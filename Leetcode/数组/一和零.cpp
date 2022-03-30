class Solution {
public:
    pair<int,int> count(string s){
        int cnt =0;
        int n = s.size();
        for(char c:s){
            if(c=='1') cnt++;
        }
        return make_pair(cnt,s.size()-cnt);
    }
    int findMaxForm(vector<string>& strs, int n, int m) {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i = 0; i< strs.size();i++){
            pair<int,int> p = count(strs[i]);
            for(int j = m;j>=p.first;j--){
                for(int k=n;k>=p.second;k--){
                    dp[j][k] = max(dp[j][k], dp[j-p.first][k-p.second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};