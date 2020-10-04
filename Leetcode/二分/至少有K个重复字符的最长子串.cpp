#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res = 0;
    int longestSubstring(string s, int k) {
        dfs(s,0,s.size()-1,k);
        return res;
    }

    void dfs(string& s,int l,int r,int k){
        if(r-l+1<k) return;
        unordered_map<char,int> m;
        int start = l;
        for(int i =l;i<=r;i++)
            m[s[i]]++;
        
        for(int i =l;i<=r;i++){
            if(m[s[i]]<k){
                dfs(s,start,i-1,k);
                start = i + 1;
            }
        }
        if(start!=l && start!=r) dfs(s,start,r,k);
        if(start==l) res = max(res,r-l+1);
        return;
    }
};