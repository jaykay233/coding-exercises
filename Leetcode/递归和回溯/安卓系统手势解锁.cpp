#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int res = 0;
    int numberOfPatterns(int m, int n) {
        vector<bool> visited(10, false);
        vector<vector<int>> jumps(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
        for(int i =1;i<=9;i++){
            helper(i,1,m,n,jumps,visited);
        }
        return res;
    }

    void helper(int num,int len,int m,int n,vector<vector<int>>& jumps,vector<bool>& visited){
        if(len>=m && len<=n) {
            res++;
        }
        if(len>n) return;
        visited[num] = true;
        for(int next = 1;next<=9;next++){
            int jump = jumps[num][next];
            if(!visited[next] && (jump==0 || visited[jump])){
                helper(next,len+1,m,n,jumps,visited);
            }
        }
        visited[num] = false;
        return;
    }
};