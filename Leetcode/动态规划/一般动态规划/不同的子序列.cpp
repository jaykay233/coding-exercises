class Solution {
public:
    vector<vector<int>> memo;
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        memo=vector<vector<int>> (m,vector<int>(n,-1));
        return dp(s,0,t,0);
    }

    int dp(string s,int i, string t, int j)
    {
        int m = s.size(), n = t.size();
        if(j == n) return 1;
        if(n - j > m - i) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int res = 0;
        if(s[i] == t[j])
            res += dp(s,i+1,t,j+1) + dp(s,i+1,t,j);
        else 
            res += dp(s,i+1,t,j);
        memo[i][j] = res;
        return res;
    }
};