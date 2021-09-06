#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> comb;
    vector<bool> visited;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        visited = vector<bool>(len, false);
        sort(nums.begin(),nums.end());
        dfs(nums);
        return res;
    }

    void dfs(vector<int>& nums){
        if(comb.size() == nums.size()){
            res.push_back(comb);
            return;
        }
        for(int i = 0; i < nums.size(); i ++){
            if(i>0 && nums[i] == nums[i-1] && !visited[i-1] || visited[i]) continue;
            comb.push_back(nums[i]);
            visited[i] = true;
            dfs(nums);
            visited[i] = false;
            comb.pop_back();
        }
    }
};