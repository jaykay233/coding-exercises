//第一种，用栈
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //encoded_string = k[encoded_string]
    string getString(vector<string>& v){
        string ret = "";
        for(const auto& s:v){
            ret += s;
        }
        return ret;
    }

    string getDigits(string &s, int& ptr){
        string ret = "";
        while(ptr<s.size() && isdigit(s[ptr])){
            ret.push_back(s[ptr++]);
        }
        return ret;
    }
    
    string decodeString(string s) {
        vector<string> stk;
        int ptr = 0;
        while(ptr<s.size()){
            char cur = s[ptr];
            if(isdigit(cur)){
                string digits = getDigits(s,ptr);
                stk.push_back(digits);
            }else if(isalpha(cur) || cur == '['){
                stk.push_back(string(1,s[ptr++]));
            }else{
                ++ptr;
                vector<string> sub;
                while(!stk.empty() && stk.back()!="["){
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                reverse(sub.begin(),sub.end());
                int reptime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while(reptime--) t += o;
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};

//