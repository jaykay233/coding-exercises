#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i =0;i<m;i++){
            for(int j =1;j<n;j++)
                matrix[i][j] += matrix[i][j-1];
        }
        int ans =0 ;
        for(int l = 0;l<n;l++){
            for(int r = l ;r<n;r++){
                unordered_map<int,int> vis;
                vis[0] = 1;
                int tot = 0;
                for(int k = 0;k<m;k++){
                    if(l ==0) tot += matrix[k][r];
                    else tot += matrix[k][r] - matrix[k][l-1];
                    
                    if(vis.find(tot- target)!=vis.end())
                        ans += vis[tot - target];
                    vis[tot] ++;
                }
            }
        }
        return ans;
    }
};