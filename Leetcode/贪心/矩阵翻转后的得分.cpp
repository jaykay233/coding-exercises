#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int ret = m * (1<<(n-1));
        for(int j=1;j<n;j++){
            int noOnes= 0 ;
            for(int i =0;i<m;i++){
                if(A[i][0]==1){
                    noOnes += A[i][j];
                }else{
                    noOnes += 1-A[i][j];
                }
            }
            int k = max(noOnes, m - noOnes);
            ret += k*(1<<(n-j-1));
        }
        return ret;
    }
};