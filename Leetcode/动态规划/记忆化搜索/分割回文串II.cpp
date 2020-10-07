class Solution {
public:
    vector<vector<bool>> dp;
    vector<int> v;
    int minCut(string s) {
        int n = s.size();
        dp = vector<vector<bool>>(n,vector<bool>(n,false));
        v = vector<int>(n,-1);
        for(int i =0;i<s.size();i++){   
            dp[i][i] = true;
            if(i+1<s.size()) dp[i][i+1] = (s[i]==s[i+1]);
        }
        for(int i = n-1;i>=0;i--){
            for(int j =i+2;j<n;j++){
                if(s[i]!=s[j]) dp[i][j] = false;
                else dp[i][j] = dp[i+1][j-1];
            }
        }
        return minCut(s,0)-1;
    }


    int minCut(string s,int i){
        if(i==s.size()) return 0;
        if(v[i]!=-1) return v[i];
        int mincut = s.size();
        for(int j =i;j<s.size();j++){
            if(dp[i][j]) 
                mincut = min(mincut, 1 + minCut(s,j+1));
        }
        return v[i] = mincut;
    }

};