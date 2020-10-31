class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        for(int i =0;i<nums.size();i++){
            int num = nums[i];
            auto it  = s.lower_bound(num);
            if(it!=s.end() && abs((long long)*it-num)<=t) return true;
            if(it!=s.begin() && abs((long long)*(--it)-num)<=t ) return true;
            s.insert(num);
            if(s.size()>k)
                s.erase(nums[i-k]);
        }
        return false;
    }
};