#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;
        for(int i =2*nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i%nums.size()]){
                st.pop();
            }
            res[i%nums.size()] = st.empty()?-1:nums[st.top()];
            st.push(i%nums.size());
        }
        return res;
    }
};