#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    unordered_map<int,int> m;
    int total;
    int row,col;
    Solution(int n_rows,int n_cols){
        total = n_rows * n_cols;
        row = n_rows;
        col = n_cols;
    }

    vector<int> flip(){
        int r = rand()%(total--);
        int x = m.find(r)!=m.end()?m[r]:r;
        m[r]=m.find(total)!=m.end()?m[total]:total;
        return {x/col,x%col};
    }

    void reset(){
        m.clear();
        total=row*col;
    }
};