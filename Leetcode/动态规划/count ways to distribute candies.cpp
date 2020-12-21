#include <bits/stdc++.h>
using namespace std;
class Solution{
    const int mod = 1e9+7;
    int waysToDistribute(int n,int k){
        vector<vector<int>> res(n,vector<int>(k));
        for(int i=0;i<n;i++){
            res[i][0] = 1;
        }
        for(int j=1;j<k;j++){
            for(int i=j;i<n;i++){
                res[i][j] = (res[i-1][j] * (j+1) + res[i-1][j-1]) % mod;
            }
        }
        return (int)res[n-1][k-1];
    }
};