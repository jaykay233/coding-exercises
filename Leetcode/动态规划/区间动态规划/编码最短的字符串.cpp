#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> dp;
    string encode(string s) {
        int n = s.size();
        dp = vector<vector<string>>(n,vector<string>(n));
        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j = i + len - 1;
                dp[i][j] = compress(s,i,j);
                if(len>4){
                    for(int k=i;k<j;k++){
                        string split = dp[i][k] + dp[k+1][j];
                        if(dp[i][j].size() > split.size()){
                            dp[i][j] = split;
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }

    string compress(string s,int i,int j){
        string t = s.substr(i,j-i+1);
        if(t.size()<5) return t;
        int p = (t+t).find(t,1);
        if(p!=t.size()){
            int cnt = t.size()/p;
            return to_string(cnt) + "[" + dp[i][i+p-1] + "]";
        }
        return s;
    }
};