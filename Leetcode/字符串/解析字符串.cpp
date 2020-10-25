//方法论题目
//https://leetcode-cn.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getDigits(string s,int & pos){
        string res = "";
        while(pos<s.size() && isdigit(s[pos])){
            res+=s[pos];
            pos++;
        }
        return res;
    }

    string getString(vector<string>& sub){
        string t = "";
        for(string x:sub) t+=x;
        return t;
    }

    string decodeString(string s) {
        vector<string> stk;
        int pos =0;
        while(pos<s.size()){
            char c = s[pos];
            if(isdigit(c)) {
                string t = getDigits(s,pos);
                stk.push_back(t);
            }
            else if(isalpha(c) || c=='['){
                stk.push_back(string(1,s[pos++]));
            }else{
                ++pos;
                vector<string> sub;
                while(!stk.empty() && stk.back()!="["){
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(),sub.end());
                stk.pop_back();
                int reptime = stoi(stk.back());
                stk.pop_back();
                string t, o =getString(sub);
                while(reptime--) t+=o;
                stk.push_back(t);
            }
        }
        return getString(stk);        
    }

   
};

class Solution {
public:
    int pos = 0;
    string s;
    string getDigits(){
        string digits="";
        while(pos<s.size() && isdigit(s[pos])){
            digits+=s[pos];
            pos++;
        }
        return digits;
    }

    string getString(){
        if(pos==s.size() || s[pos]==']' || s[pos]=='[')
            return "";
        char cur = s[pos];
        int repTime = 1;
        string ret;
        if(isdigit(cur)){
            repTime = stoi(getDigits());
            pos++;
            string str = getString();
            pos++;
            while(repTime--)
                ret+=str;
        }else if(isalpha(cur)){
            ret+=string(1,s[pos++]);
        }
        return ret + getString();
    }

    string decodeString(string s) {
        this->s = s;
        pos = 0;
        return getString();
    }
};