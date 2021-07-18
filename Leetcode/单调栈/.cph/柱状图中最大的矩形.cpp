//https://blog.csdn.net/qq_17550379/article/details/85093224
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        int res= 0;
        heights.push_back(0);
        for(int i =0;i<heights.size();i++){
            if(st.empty() || !st.empty() && heights[i] > heights[st.top()]){
                st.push(i);
            }else{
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty()? i : i - st.top() - 1));
            }
        }
        return res;
    }
};