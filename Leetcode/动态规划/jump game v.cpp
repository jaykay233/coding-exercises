#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int d;
    int maxJumps(vector<int>& A, int d) {
        vector<int>dp(A.size(),-1);
        int res=0;
        this->d=d;
        for(int i=0;i<A.size();i++){
            res=max(res,dfs(A,dp,i));
        }
        return res;
    }
    
    int dfs(vector<int>& A,vector<int>& dp,int index){
        int val=A[index];
        if(dp[index]!=-1)return dp[index];
        int step=1;
        int M=0;
        for(int i=1;i<=d;i++){
            if(index+i>=A.size())break;
            if(A[index+i]>=val)break;
            M=max(M,dfs(A,dp,index+i));
        }
        for(int i=1;i<=d;i++){
            if(index-i<0)break;
            if(A[index-i]>=val)break;
            M=max(M,dfs(A,dp,index-i));
        }
        dp[index]=step+M;
        return dp[index];
    }
};