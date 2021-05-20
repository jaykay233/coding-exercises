#include <bits/stdc++.h>
using namespace std;
int dp[255][255][26];
class Solution {
public:
    int idx(char c){
        return c - 'a';
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,0,sizeof dp);
        const int N = s.size();
        for(int len=2;len<=N;len++){
            for(int i =0;i+len-1<N;i++){
                const int j = i + len -1;
                if(len == 2){
                    if(s[i] == s[j]){
                        dp[i][j][idx(s[i])] = 2;
                    }
                }else{
                    if(s[i]==s[j]){
                        int i_idx = idx(s[i]);
                        for(int c=0;c<26;c++){
                            if(c==i_idx) continue;
                            dp[i][j][i_idx] = max(dp[i][j][i_idx],dp[i+1][j-1][c] + 2);
                            dp[i][j][c] = dp[i+1][j-1][c];
                        }
                    }else{
                        int i_idx = idx(s[i]);
                        int j_idx = idx(s[j]);
                        dp[i][j][i_idx] = dp[i][j-1][i_idx];
                        dp[i][j][j_idx] = dp[i+1][j][j_idx];
                        for(int c=0;c<26;c++){
                            if(c==i_idx || c==j_idx) continue;
                            dp[i][j][c] = dp[i+1][j-1][c];
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int c=0;c<26;c++){
            ans = max(ans,dp[0][N-1][c]);
        }
        return ans;
    }
};