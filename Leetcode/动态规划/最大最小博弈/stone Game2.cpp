#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum(n+1,0);
        for(int i = n-1;i>=0;i--)
            sum[i] = piles[i] + sum[i+1];
        vector<vector<int>> f(n+1,vector<int>(n+1));
        
        for(int i =n-1;i>=0;i--){
            for(int j =1;j<=n;j++){
                for(int k =1;k<=2*j && i+k<=n;k++){
                    f[i][j] = max(f[i][j], sum[i] - f[i+k][max(j,k)]);
                }
            }
        }
        return f[0][1];
    }
};