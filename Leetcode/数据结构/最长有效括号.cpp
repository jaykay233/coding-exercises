#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int longestValidPalindrome(string s){
        stack<int> st;
        int maxlen = 0;
        vector<int> dp(s.size(),0);
        for(int i =0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i] == ')'){
                if(!st.empty()){
                    dp[i] = (st.top()>1=1?dp[st.top()-1]:0) + i - st.top() + 1;
                    maxlen = max(maxlen, dp[i]);
                    st.pop();
                }else{
                    continue;
                }
            }
        }
        return maxlen;
    }
};

//https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
//因为只需要保留其中一个最近的索引，其实并不需要开个数组
class Solution2{
public:    
    int longestValidParentheses(string s){
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i =0;i<s.size();i++){
            if(s[i]=='(')
                stk.push(i);
            else{
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                else{
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
}