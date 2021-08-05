#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    string minWindow(string s1, string s2) 
    {
        if(s1==s2) return s1;
        int n1 = s1.size();
        int n2 = s2.size();

        int dp[n1+1][n2+1];
        memset(dp, 0xff, sizeof(dp));

        string res = s1;

        dp[0][0] = 0;
        for (int i = 0; i < n1; i ++)
            dp[i][0] = i;

        for (int i = 1; i <n1 + 1; i ++)
        {
            for (int j = 1; j < n2 + 1; j ++)
            {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
                
                //------------- 更新res
                if (dp[i][n2] != -1)
                {
                    if (i - dp[i][n2] < (int)res.size())
                    {
                        res = s1.substr(dp[i][n2], i - dp[i][n2]);
                    }
                }
            }
        }            

        return (res == s1 ? "" : res);
    }
};
