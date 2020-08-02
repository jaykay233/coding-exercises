#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> mp;
    bool isMatch(string s, string p) {
        mp = vector<vector<int>>(s.size(),vector<int>(p.size(),-1));
        return dp(s,0,p,0);
    }
    
    bool dp(string s,int i,string p,int j){
        if(i>=s.size() && j >= p.size()) return true;
        else if(i>=s.size()){
            if(j>=p.size()) return true;
            else if(j+1<p.size() && p[j+1]=='*') return dp(s,i,p,j+2);
            else return false;
        }else if(j>=p.size()){
            return false;
        }
        if(mp[i][j]!=-1) return mp[i][j] == 1;
        
        if(j+1<p.size() && p[j+1]=='*'){
            if(dp(s,i,p,j+2)) return mp[i][j] = 1;
            int k = i;
            while(k<s.size() && (s[k]==p[j] || p[j]=='.') ){
                if(dp(s,k+1,p,j+2)) return mp[i][j] = 1;
                k++;
            }
        }
        
        if((p[j]=='.' || s[i]==p[j])  && dp(s,i+1,p,j+1)) return mp[i][j] = 1;

        
        return mp[i][j] = 0;
    }
    
};