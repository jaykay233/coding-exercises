#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    int maxSatisfaction(vector<int>& satisfaction){
        sort(satisfaction.begin(),satisfaction.end(),[](int x,int y){
            return x>y;
        });
        int pre = 0;
        int sum = 0;
        for(int i =0;i<satisfaction.size();i++){
            if(pre+ satisfaction[i]>0){
                pre += satisfaction[i];
                sum += pre;
            }
            else break;
        }
        return sum;
    }
};