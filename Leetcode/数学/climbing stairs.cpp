#include <iostream>
#include <vector>
using namespace std;
//斐波那契矩阵形式

class Solution {
public:
    int climbStairs(int n) {
        vector<vector<int>> q = {{1,1},{1,0}};
        vector<vector<int>> res = pow(q,n);
        return res[0][0];
    }
    
    vector<vector<int>> pow(vector<vector<int>> a,int n){
        vector<vector<int>> ret = {{1,0},{0,1}};
        while(n>0){
            if((n&1)==1){
                ret = multiply(ret,a);
            }
            n>>=1;
            a = multiply(a,a);
        }
        return ret;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& a,vector<vector<int>>& b){
        vector<vector<int>> c(2,vector<int>(2));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
};


int main(){
    return 0;
}