#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> getMatrix(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int maxsum = INT_MIN;
        vector<int> res(4);
        int sum = 0;
        int bestr = 0;
        int bestc =0 ;
        for(int r1=0;r1<m;r1++){
            vector<int> dp(n,0);
            for(int r2=r1;r2<m;r2++){
                sum = 0;
                for(int c=0;c<n;c++){
                    dp[c] += matrix[r2][c];
                    if(sum>0)
                        sum += dp[c];
                    else{
                        sum = dp[c];
                        bestr = r1;
                        bestc = c;
                    }
                    if(sum>maxsum){
                        maxsum = sum;
                        res[0] = bestr;
                        res[1] = bestc;
                        res[2] = r2;
                        res[3] = c;
                    }
                }
            }
        }
        return res;
    }    
};