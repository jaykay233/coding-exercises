#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix,int target){
        int r = matrix.size(),c=matrix[0].size();
        vector<vector<int>> ps(r+1,vector<int>(c+1));
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + matrix[i-1][j-1];
            }
        }

        int count =0,cursum;
        unordered_map<int,int> h;
        for(int r1=1;r1<=r;r1++){
            for(int r2=r1;r2<=r;r2++){
                h.clear();
                h[0]=1;
                for(int col=1;col<=c;col++){
                    cursum = ps[r2][col] - ps[r1-1][col];
                    count += h[cursum-target];
                    h[cursum] += 1;
                }
            }
        }
        return count;
    }
};