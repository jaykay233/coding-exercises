#include <bits/stdc++.h>
using namespace std;

class Solution{
    string tictactoe(vector<vector<int>>& moves){
        int m = moves.size();
        int count[8];
        for(int i=m-1;i>=0;i-=2){
            count[moves[i][0]]++;
            count[moves[i][1]+3]++;
            if(moves[i][0] == moves[i][1])
                count[6]++;
            if(moves[i][0] + moves[i][1] == 2)
                count[7]++;
            if(count[moves[i][0]] == 3 || count[moves[i][1]+3]==3 || count[6]==3 || count[7]==3)
                return m%2==0?"B":"A";
        }
        if(moves.size()<9)
            return "Pending";
        return "Draw";
    }
};