#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,vector<int>> m;
    int n;
    const int mod = 1e9+7;
    vector<vector<int>> dp;
    int knightDialer(int n) {
        this->n = n;
        m[0] = {4,6};
        m[1] = {6,8};
        m[2] = {7,9};
        m[3] = {4,8};
        m[4] = {3,9,0};
        m[5] = {};
        m[6] = {1,7,0};
        m[7] = {2,6};
        m[8] = {1,3};
        m[9] = {2,4};
        int dp[2][10];
        for(int i=0;i<10;i++) dp[0][i] = 1;
        for(int hops=0;hops<n-1;hops++){
            memset(dp[~hops & 1],0,sizeof(dp[~hops & 1]));
            for(int node=0;node<10;node++){
                for(int nei:m[node]){
                    dp[~hops & 1][nei] += dp[hops & 1][node];
                    dp[~hops & 1][nei] %= mod;
                }
            }
        }

        long ans =0 ;
        for(int x:dp[~n&1]){
            ans+=x;
        }
        return ans % mod;
    }

};