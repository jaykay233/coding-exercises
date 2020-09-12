#include <bits/stdc++.h>
using namespace std;

class Solution{
    bool check(int limit,vector<int> cost,int day){
        int use_day=1,total_time =0, max_time =0;
        for(int i =0;i<cost.size();i++){
            int nexttime = min(cost[i],max_time);
            if(nexttime+total_time<=limit){
                total_time += nexttime;
                max_time = max(max_time,cost[i]);
            }else{
                use_day++;
                total_time = 0;
                max_time = cost[i];
            }
        }
        return use_day<=day;
    }    

    int minTime(vector<int>& time,int m){
        int left,right,middle;
        left = right= 0 ;
        for(int i =0;i<time.size();i++){
            right += time[i];
        }
        while(left<right){
            middle = left + right >> 1;
            if(check(middle,time,m)) right = middle;
            else left = middle +1;
        }
        return left;
    }
};