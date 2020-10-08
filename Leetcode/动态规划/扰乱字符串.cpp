#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,bool> m;
    bool isScramble(string s1, string s2) {
        string s = s1 + "-" + s2;
        if(m.count(s)) return m[s];
        if(s1.size()!=s2.size()) return false;
        if(s1==s2) return true;
        if(string(s1.rbegin(),s1.rend()) == s2) return true;
        int len = s1.size();
        for(int l=1;l<len;l++){
            if(isScramble(s1.substr(0,l),s2.substr(0,l)) && isScramble(s1.substr(l),s2.substr(l)) ) return m[s]=true;
            if(isScramble(s1.substr(0,l),s2.substr(len-l)) && isScramble(s1.substr(l),s2.substr(0,len-l))) return m[s]=true; 
        }
        return m[s] = false;
    }
};