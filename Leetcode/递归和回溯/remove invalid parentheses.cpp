#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<string> res;
    vector<string> removeInvalidParentheses(string s) {
        dfs(s,0,0,0,"");
        if(res.empty()) return {""};
        return vector<string>(res.begin(),res.end());
    }

    void dfs(string& s,int i,int left,int right,string total){
        if(i==s.size()){
            if(left!=right) return;
            if(res.empty()) {
                res.insert(total);
            }else{
                if(res.count(total)) return;
                if(res.begin()->size()<total.size()){
                    res.clear();
                    res.insert(total);
                }else if(res.begin()->size()==total.size()){
                    res.insert(total);
                }                
            }
            return;
        }
        if(!res.empty() && s.size()-i+total.size() < res.begin()->size()) return;
        if(s[i]!='(' && s[i]!=')') {
            dfs(s,i+1,left,right,total+s[i]);
            return;
        }
        if(left>right){
            if(left>right+s.size()-i) return;
            if(s[i]=='('){
                dfs(s,i+1,left+1,right,total+'(');
            }
            else if(s[i]==')'){
                dfs(s,i+1,left,right+1,total+')');
            }
            
            dfs(s,i+1,left,right,total);
            
        }else if(left==right){
            if(s[i]==')') {
                dfs(s,i+1,left,right,total);
            }
            else if(s[i]=='(') {
                dfs(s,i+1,left+1,right,total+'(');
            }
            dfs(s,i+1,left,right,total);
        }
    }
    
};