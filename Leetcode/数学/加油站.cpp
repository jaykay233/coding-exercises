#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int canCompleteCircuit(vector<int>& gas,vector<int>& cost){
        for(int i =0;i<gas.size();i++){
            gas[i] -= cost[i];
        }
        int total_tank = 0;
        int cur_tank =0 ;
        int start =0;
        for(int i =0;i<gas.size();i++){
            total_tank += gas[i];
            cur_tank += gas[i];
            if(cur_tank<0){
                cur_tank = 0;
                start = i + 1;
            }
        }
        return total_tank>=0?start:-1;
    }
};