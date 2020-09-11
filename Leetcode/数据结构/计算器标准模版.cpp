#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<char> stack_opt;
        stack<long long> stack_num;
        int i =0 ;
        unordered_map<char,int> m;
        m['(']=0;m[')']=0;m['+']=1;m['-']=1;m['*']=2;m['/']=2;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            else if(s[i]>='0' && s[i]<='9'){
                int j = i;
                while(i+1<s.size() && s[i+1]>='0' && s[i+1]<='9') i++;
                long long num = stoll(s.substr(j,i+1-j));
                stack_num.push(num);
            }
            else if(s[i]=='('){
                stack_opt.push('(');
            }else if(s[i]==')'){
                while(stack_opt.top()!='('){
                    char c = stack_opt.top();stack_opt.pop();
                    long long A = stack_num.top(); stack_num.pop();
                    long long B = stack_num.top(); stack_num.pop();
                    long long val = cal(A,B,c);
                    stack_num.push(val);
                }
                stack_opt.pop();
            }else{
                while(!stack_opt.empty() && m[s[i]] <= m[stack_opt.top()]){
                    char c = stack_opt.top();stack_opt.pop();
                    long long A = stack_num.top(); stack_num.pop();
                    long long B = stack_num.top(); stack_num.pop();
                    long long val = cal(A,B,c);
                    stack_num.push(val);
                }
                stack_opt.push(s[i]);
            }
            i++;
        }
        while(!stack_opt.empty()){
            char c = stack_opt.top();stack_opt.pop();
            long long A = stack_num.top(); stack_num.pop();
            long long B = stack_num.top(); stack_num.pop();
            stack_num.push(cal(A,B,c));
        }
        return stack_num.top();
    }

    long long cal(long long A,long long B,char C){
        if(C=='+') return A + B;
        else if(C=='-') return B - A;
        else if(C=='*') return A * B;
        else return B / A;
    }
};

