#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<char,int> m = {{'-',1},{'+',1},{'*',2},{'/',2},{'%',3},{'^',3}};
    void replace(string& s){
        int pos = s.find(" ");
        while(pos!=-1){
            s.replace(pos,1,"");
            pos = s.find(" ");
        }
    }

    int calculate(string s) {
        stack<int> nums;
        nums.push(0);
        stack<char> ops;
        replace(s);
        int n = s.size();
        for(int i =0;i<s.size();i++){
            char c = s[i];
            if(c=='(')
                ops.push(c);
            else if(c==')'){
                while(!ops.empty() && ops.top()!='('){
                    calc(nums,ops);
                }
                ops.pop();
            }else{
                if(isdigit(c)){
                    int cur_num = 0;
                    int j = i;
                    while(j<s.size() && isdigit(s[j])){
                        cur_num = cur_num * 10 + (s[j++]-'0');
                    }
                    nums.push(cur_num);
                    i = j - 1;
                }
                else{
                    if(i>0 && (s[i-1] == '(' || s[i-1]=='+' || s[i-1]=='-'))
                        nums.push(0);
                    while(!ops.empty() && ops.top()!='('){
                        char prev = ops.top();
                        if(m[ops.top()] >= m[c]){
                            calc(nums, ops);
                        }else{
                            break;
                        }
                    }
                    ops.push(c);
                }
            }
        }
        
        while(!ops.empty() && ops.empty()!='(')
            calc(nums,ops);
        return nums.top();
    }   

    void calc(stack<int>& nums,stack<char>& ops){
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char c = ops.top(); ops.pop();
        if(c=='+') nums.push(a + b);
        else if(c=='-') nums.push(a - b);
        else if(c=='*') nums.push(a * b);
        else if(c=='/') nums.push(a/b);
        else if(c=='^') nums.push(pow(a,b));
    }

};