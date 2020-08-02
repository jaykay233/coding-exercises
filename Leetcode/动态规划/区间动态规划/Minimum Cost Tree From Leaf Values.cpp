#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

//解法1 区间动态规划
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> max_(n,vector<int>(n));
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++)
            max_[i][i] = arr[i];
        
        for(int d = 1 ; d <= n ; d ++)
        {
            for(int i = 0 ; i + d < n ; i++)
            {
                int j = i + d;
                max_[i][j] = max(max_[i][j - 1],arr[j]);
            }
        }
        
        for(int i =0;i<n-1;i++)
            dp[i][i+1] = arr[i]*arr[i+1];
        
        for(int d = 2;d<=n;d++){
            for(int i=0;i+d<n;i++){
                int j = i + d;
                int cur_min = INT_MAX;
                for(int k=i;k<j;k++){
                    cur_min = min(cur_min,dp[i][k] + dp[k+1][j] + max_[i][k] * max_[k+1][j]);
                }
                dp[i][j] = cur_min;
            }
        }
        
        return dp[0][n-1];
    }
};

//解法2 单调栈
class Solution2{
public:
    int mctFromLeafValues(vector<int>& arr){
        int n =arr.size();
        stack<int> st;
        st.push(INT_MAX);
        int res= 0;
        for(int i=0;i<n;i++){
            if(st.top()>=arr[i])
                st.push(arr[i]);
            else{
                while(arr[i]>st.top()){
                    int cur = st.top();st.pop();
                    int min_val = min(st.top(),arr[i]);
                    res += cur * min_val;
                }
                st.push(arr[i]);
            }
        }

        while(st.size()>2){
            int cur =st.top();st.pop();
            res+= cur * st.top();
        }
        return res;
    }
};