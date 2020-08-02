#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> > q;
        for(int i=0;i<mat.size();i++){
            q.push({get_index(mat[i]),i});
        }
        vector<int> res;
        while(q.size() && k){
            auto p = q.top();q.pop();
            res.push_back(p.second);
            k--;
        }
        return res;
    }
    
    int get_index(vector<int> mat){
        int l = 0, r = mat.size()-1;
        while(l<r){
            int m = (l+r+1)>>1;
            if(mat[m]==1) l = m;
            else r = m-1;
        }
        if(mat[l]!=1) l--;
        return l;
    }
    
};