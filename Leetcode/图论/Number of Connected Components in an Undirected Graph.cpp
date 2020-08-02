#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> p;
    
    int find(int i){
        if(p[i] == i) return p[i];
        return p[i] = find(p[i]);
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        p = vector<int>(n);
        for(int i =0;i<n;i++) p[i] = i;
        for(int i =0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int fa = find(a), fb = find(b);
            if(p[fa]!=fb){
                p[fa] = fb;
            }
        }
        int cnt =0;
        for(int i =0;i<n;i++){
            if(p[i]==i) cnt++;
        }
        return cnt;
    }
};