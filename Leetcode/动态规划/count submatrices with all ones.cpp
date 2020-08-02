#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    int numSubmat(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> presum(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + mat[i-1][j-1];
            }
        }

        int res= 0;
        for(int row=1;row<=m;row++){
            for(int len = 1;row+len-1<=m;len++){
                for(int col = 1;col<=n;col++){
                    if(getSum(presum,row,col,row+len-1,col)==len){
                        int temp = col;
                        while(temp<=n && getSum(presum,row,temp,row+len-1,temp)==len) temp++;
                        int length = temp - col;
                        res += length * (length+1)/2;
                        col = temp-1;
                    }
                }
            }
        }
        return res;
    }

    int getSum(vector<vector<int>>& presum,int x1, int y1, int x2 ,int y2){
        return presum[x2][y2] - presum[x2][y1-1] - presum[x1-1][y2] + presum[x1-1][y1-1];
    }
};

int main(){



    return 0;
}