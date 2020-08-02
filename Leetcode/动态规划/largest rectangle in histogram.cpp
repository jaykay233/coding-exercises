#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        heights.push_back(0);
        int maxsize =0;
        for(int i =0;i<heights.size();i++){
            if(st.empty() || heights[i] > heights[st.top()]) st.push(i);
            else{
                int cur = st.top();st.pop();
                maxsize = max(maxsize,heights[cur] * (st.empty()?i:i-st.top()-1));
                i--;
            }
        }
        return maxsize;
    }
};

int main(){
    Solution solution;
    return 0;
}