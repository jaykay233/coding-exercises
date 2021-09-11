#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<char,string> m;
    unordered_set<string> st;
    bool wordPatternMatch(string pattern, string s) {
        return dfs(pattern, 0, s, 0);
    }

    bool dfs(string pattern, int i, string s,int j){
        if(i == pattern.size() && j == s.size()) return true;
        if(j == s.size() || i == pattern.size()) return false;
        if(m.count(pattern[i])) return s.substr(j,m[pattern[i]].size()) == m[pattern[i]] && dfs(pattern, i + 1, s, j + m[pattern[i]].size());
        else{
            for(int k = j; k < s.size(); k ++){
                string t = s.substr(j, k-j+1);
                if(st.count(t)) continue;
                m[pattern[i]] = t;
                st.insert(t);
                if(dfs(pattern, i + 1, s, j + t.size())) return true;
                m.erase(pattern[i]);
                st.erase(t);
            }
        }
        return false;
    }
};