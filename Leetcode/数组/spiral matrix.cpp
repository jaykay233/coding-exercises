#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> dr = {0,1, 0,-1};
        vector<int> dc = {1, 0, -1,0};
        vector<vector<bool>> seen(matrix.size(),vector<bool>(matrix[0].size(),false));
        vector<int> ans;
        int R = matrix.size();
        int C = matrix[0].size();
        int r =0, c =0, di = 0;
        for(int i =0;i<R*C;i++){
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if(cr>=0 && cr<R && cc>=0 && cc<C && !seen[cr][cc]){
                r = cr;
                c = cc;
            }
            else{
                di = (di+1)%4;
                r = r + dr[di];
                c = c + dc[di];
            }
        }
        return ans;
    }
};