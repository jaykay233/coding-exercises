//x如果到不了y,那么x和y中间的任意一段路都到不y
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int canCompleteCircuit(vector<int>& gas,vector<int>>& cost){
        int n = gas.size();
        int i =0;
        int cnt = 0;
        while(i<n){
            int sumOfGas=0,sumOfCost =0;
            cnt =0;
            while(cnt<n){
                int j = (i+cnt) %n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if(sumOfCost > sumOfGas)
                    break;
                cnt++;
            }
            if(cnt==n)
                return i;
            else{
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};