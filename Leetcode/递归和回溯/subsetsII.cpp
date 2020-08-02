#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }
    
    void dfs(vector<int>& nums,int u){
        if(u == nums.size()){
            res.push_back(path);
            return;
        }
        int k = 0;
        while(u+k<nums.size() && nums[u+k]==nums[u]) k++;
        for(int i =0;i<=k;i++){
            dfs(nums,u+k);
            path.push_back(nums[u]);
        }
        for(int i =0;i<=k;i++) path.pop_back();
    }
};

int main(){
    return 0;
}