#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool ok = false;
        vector<int> res;
        int m = mat.size();
        if(m==0) return res;
        int n = mat[0].size();
        if(n==0) return res;
        bool bxFlag = true;
        for(int i = 0;i<m+n;i++){
            int pm = bxFlag ? m : n;
            int pn = bxFlag ? n : m;

            int x = (i<pm) ? i : pm - 1;
            int y = i - x;
            while(x>=0 && y<pn){
                res.push_back(bxFlag?mat[x][y] : mat[y][x]);
                x--;
                y++;
            }
            bxFlag = !bxFlag;
        }
        return res;
    }
};