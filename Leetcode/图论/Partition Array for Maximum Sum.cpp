//确定是图论而不是dp？
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len = A.size();
        vector<int> dp(len);
        for(int i =0;i<len;i++){
            dp[i] = -0x3f3f3f3f;
            int curmax = A[i];
            for(int k =1;k<=K && i-k+1>=0;k++){
                curmax = max(curmax,A[i-k+1]);
                dp[i] = max(dp[i],(i-k<0?0:dp[i-k]) + curmax * k);
            }
        }
        return dp.back();
    }
};

int main(){
    return 0;
}