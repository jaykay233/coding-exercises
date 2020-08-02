#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> father;
    
    int find(int i){
        if(father[i]==i) return i;
        return father[i] = find(father[i]);
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        father = vector<int>(n);
        for(int i =0;i<n;i++){
            father[i] = i;
        }
        for(auto edge:edges){
            int a = edge[0];
            int b = edge[1];
            int fa = find(a);
            int fb = find(b);
            if(fa == fb) return false;
            father[fa] = fb;
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(father[i]==i) cnt++;
        }
        if(cnt==1) return true;
        return false;
    }
};