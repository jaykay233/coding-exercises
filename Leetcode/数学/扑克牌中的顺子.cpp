#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    bool isStraight(vector<int>& nums){
        unordered_set<int> repeat;
        int ma = 0,mi = 14;
        for(int num:nums){
            if(num==0) continue;
            ma = max(ma,num);
            mi = min(mi, num);
            if(repeat.count(num)) return false;
            repeat.insert(num);
        }
        return ma - mi < 5;
    }
};