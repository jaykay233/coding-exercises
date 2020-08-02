#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int p[60];
    void init(){
        for(int i =0;i<26;i++){
            p[i] = i;
        }
    }
    
    int find(int a){
        if(p[a]==a) return a;
        return p[a] = find(p[a]);
    }
    
    void merge(int a,int b){
        int fa = find(a);
        int fb = find(b);
        if(fa!=fb)
        p[fa] = fb;
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        init();
        vector<string> uneq;
        for(string t:equations){
            int a = t[0] - 'a';
            int b = t[3] - 'a';
            if(t[1]=='='){
                merge(a,b);
            }else{
                uneq.push_back(t);
            }
        }
        for(string t:uneq){
            int a = t[0] - 'a';
            int b = t[3] - 'a';
            if(find(a)==find(b)) return false;
        }
        return true;
    }
};