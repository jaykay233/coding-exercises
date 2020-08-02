#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int getnum(vector<int> nums){
    if(nums.empty()) return 0;
    if(nums.size()==1) return nums[0];
    vector<int> dp(nums.size(),0);
    dp[0]=nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++){
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp.back();
}


int getResult(vector<int>& nums) {
    if(nums.empty()) return 0;
    if(nums.size()==1) return nums[0];
    int t = nums.back();
    nums.pop_back();
    int l = getnum(nums);
    nums.push_back(t);
    nums.erase(nums.begin());
    int r = getnum(nums);
    return max(l,r);
}
    
    

int main(){
    int N;
    cin>>N;
    vector<int> cands;
    for(int i =0;i<N;i++){
        int d;
        scanf("%d",&d);
        cands.push_back(d);
    }
    cout<<getResult(cands)<<endl;

    return 0;
}