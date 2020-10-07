#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    int constrainedSubsetSum(vector<int>& nums,int k){
        int n = nums.size();
        int f[n+2],q[n+2];
        int hh =0 ,tt =0 ;
        int res = -0x3f3f3f3f;
        for(int i =1;i<=n;i++){
            while(hh<=tt && q[hh]<i-k) hh ++;
            f[i] = max(0,f[q[hh]]) + nums[i-1];
            res = max(res,f[i]);
            while(hh<=tt && f[q[tt]] <= f[i]) tt --;
            q[++tt] = i;
        }
        return res;
    }
};