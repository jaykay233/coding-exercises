#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,int k,int t){
        if(!k || t<0 || nums.size()<2) return false;
        set<long long> record;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(i>k)
                record.erase(nums[i-k-1]);
            set<long long>::iterator lower=record.lower_bound((long long)nums[i]-t);
            if(lower!=record.end() && abs(nums[i]-*lower)<=t)
                return true;
            record.insert(nums[i]);
        }
        return false;
    }
};