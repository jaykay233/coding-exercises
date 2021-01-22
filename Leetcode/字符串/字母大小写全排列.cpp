#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if(S.empty()) return {""};
        if(S.size()==1) {
            if(isalpha(S[0])) return {string(1,tolower(S[0])),string(1,toupper(S[0])) };
            else return {S};
        }
        vector<string> next = letterCasePermutation(S.substr(1));
        vector<string> res;

        if(isalpha(S[0])){
            char c_lower = tolower(S[0]);
            char c_upper = toupper(S[0]);
            for(string r:next){
                res.push_back(c_lower + r);
                res.push_back(c_upper + r);
            }
        }
        else{
            char c = S[0];
            for(string r:next){
                res.push_back(c + r);
            }
        }
        
        if(res.empty()) res = {""};
        return res;
    }
};