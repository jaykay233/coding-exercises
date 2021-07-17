class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int& num:nums){
            num_set.insert(num);
        }
        int longest = 0;
        for(int num:nums){
            if(!num_set.count(num - 1)){
                int cur_num = num;
                int cur_steak = 1;
                while(num_set.count(cur_num + 1)){
                    cur_num += 1;
                    cur_steak += 1;
                }
                longest = max(longest, cur_steak);
            }
        }
        return longest;
    }
};