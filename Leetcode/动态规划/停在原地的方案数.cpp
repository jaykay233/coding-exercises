#include <bits/stdc++.h>
using namespace std;

class Solution{
    static const int mod = 1e9+7;
    int numWays(int steps,int arrLen){
        arrLen = min(arrLen,steps+1);
        vector<vector<int>> f(steps+1,vector<int>(arrLen));
        f[0][0]=1;
        for(int i=1;i<=steps;i++){
            for(int j =0;j<arrLen;j++){
                for(int k=-1;k<=1;k++){
                    if(j-k>=0 && j-k<arrLen){
                        f[i][j] = (f[i][j] + f[i-1][j-k]) % mod;
                    }
                }
            }
        }        
        return f[steps][0];
    }
};