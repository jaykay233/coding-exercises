#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix[0].size();
        vector<int> height(n);

        for(int i =0;i<n;i++) height[i] = (matrix[0][i]=='1');

        int val = maxRectangle(height);

        for(int i =1;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0') height[j] = 0;
                else if(matrix[i][j]=='1') height[j] +=1;
            }
            val = max(val,maxRectangle(height));
        }
        return val;
    }

    int maxRectangle(vector<int> heights){
        stack<int> st;
        heights.push_back(0);
        int maxarea = 0;
        for(int i =0;i<heights.size();i++){
            if(st.empty() || !st.empty() && heights[i]>heights[st.top()]) st.push(i);
            else{
                int t = st.top();st.pop();
                int len;
                if(st.empty()) len = i;
                else len = i - st.top()-1;
                maxarea = max(maxarea,heights[t] * len);
                i --;
            }
        }
        return maxarea; 
    }
};