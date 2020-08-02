#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;
class Solution{
public:
    int longestValidParentheses(string s){
        stack<int> st;
        int maxlen =0 ;
        vector<int> dp(s.size());
        for(int i =0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='('){
                    dp[i] = (st.top()>=1 ? dp[st.top()-1]:0) + i -st.top()+1;
                    maxlen = max(maxlen,dp[i]);
                    st.pop();
                }else if(!st.empty()){
                    st.pop();
                }
            }
        }
        return maxlen;
    }
};


int main(){


    return 0;
}