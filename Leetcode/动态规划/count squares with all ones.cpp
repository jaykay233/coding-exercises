#include <vector>
#include <iostream>
using namespace std;

//最大数字就是这个方块内的全1矩阵个数
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n =  matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int sum = 0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                dp[i][j] = matrix[i][j];
                if(i && j && matrix[i][j])
                    dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};

int main(){
    return 0;
}