#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
public: 
    int videoStitching(vector<vector<int>>& clips,int T){
        sort(clips.begin(),clips.end(),[](vector<int> p,vector<int> q){
            return p[0]<q[0] || (p[0]==q[0] && p[1]<q[1]);
        });
        int start_time =0 ;
        int end_time =0;
        int count = 0,i=0;
        while(end_time<T){
            for(;i<clips.size() && clips[i][0]<=start_time;i++){
                end_time = max(end_time, clips[i][1]);
            }
            if(start_time == end_time) return -1;
            start_time = end_time;
            count++;
        }
        return count;
    }
};