#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,bool> m;
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(m.count(s+"_"+p)) return m[s+"_"+p];
        if(p[1]=='*'){
            return m[s+"_"+p] = (isMatch(s,p.substr(2)) || !s.empty() && (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1),p));
        }else
            return m[s+"_"+p] = (!s.empty() && (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1),p.substr(1)));
    }
};