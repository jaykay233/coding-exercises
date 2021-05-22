//裸的暴力dp和用单调栈优化过的dp
//https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int mctFromLeafValues(vector<int>& arr){
        stack<int> st;
        st.push(INT_MAX);
        int res =0 ;
        for(int i=0;i<arr.size();i++){
            while(arr[i] >= st.top()){
                int t = st.top();
                st.pop();
                res += t* min(st.top(),arr[i]);
            }
            st.push(arr[i]);
        }
        while(arr.size()>2){
            int t = st.top();st.pop();
            res += t * st.top();
        }
        return res;
    }
};