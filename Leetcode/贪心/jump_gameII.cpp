#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution{
public: 
    int jump(vector<int>& nums){
        int i=0;
        int end_time =0;
        int start_time =0 ;
        int cnt =0 ;
        while(end_time < nums.size()-1){
            for(;i<nums.size() && i<=start_time;i++){
                end_time = max(end_time, i + nums[i]);
            }
            cnt++;
            start_time = end_time;
        }
        return cnt;
    }
};