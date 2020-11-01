#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        int mins[15010];
        mins[0] = nums[0];
        for(int i=1;i<len;i++){
            mins[i] = min(mins[i-1],nums[i]);
        }

        stack<int> st;
        for(int j=len-1;j>=0;j--){
            if(nums[j]>mins[j]){
                while(!st.empty() && st.top() <= mins[j]) st.pop();
                if(!st.empty() && st.top() < nums[j]) return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};