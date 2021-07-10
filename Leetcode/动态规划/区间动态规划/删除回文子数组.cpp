//https://leetcode-cn.com/problems/palindrome-removal/solution/dp-by-mike-meng-14/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:   
    int minimumMoves(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0x3f3f3f3f));
        for(int i =0;i<n;i++) dp[i][i] =1 ;
        for(int i =0;i + 1<n;i++){
            if(arr[i]==arr[i+1]) dp[i][i+1] = 1;
            else dp[i][i+1] = 2;
        }
        int size = arr.size();
        for(int i = size-2;i>=0;i--){
            for(int j = i + 1;j<size;j++){
                for(int k=i;k<j;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                if(arr[i] == arr[j]) dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
            }
        }
        return dp[0][n-1];
    }
};