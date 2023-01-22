#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// https://leetcode.cn/problems/longest-valid-parentheses/solution/shou-hua-tu-jie-zhan-de-xiang-xi-si-lu-by-hyj8/

int longestValidParentheses(string s) {
    vector<int> dp(s.size());
    int max_size =0 ;
    for(int i = 1; i < s.size(); i ++){
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            max_size = max(max_size, dp[i]);
        }
    }
    return max_size;
}

int longestValidParentheses2(string s)
{
    int maxlen = 0;
    stack<int> st;
    st.push(-1);
    for(int i  =0;i<s.size();i++){
        char c = s[i];
        if(c == '(')
            st.push(i);
        else 
        {
            st.pop();
            if(st.empty())
                st.push(i);
            else{
                maxlen = max(maxlen, i - st.top());
            }
        }
    }
    return maxlen;
}

int main()
{
    string s = "(()";
    int l1 = longestValidParentheses(s);
    cout << l1 << endl;
    return 0;
}