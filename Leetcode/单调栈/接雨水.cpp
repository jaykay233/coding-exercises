#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height){
        int n = height.size(), ans =0 ;
        stack<int> st;
        for(int i = 0;i < n;i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int top = st.top();
                st.pop();
                if(st.empty()) break;
                ans+=(i-st.top()-1)*(min(height[i],height[st.top()])-height[top]);
            }
            st.push(i);
        }
        return ans;
    }
};

int main(){


    return 0;
}