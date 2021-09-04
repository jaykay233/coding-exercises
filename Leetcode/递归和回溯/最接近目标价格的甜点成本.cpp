#include <bits/stdc++.h>
using namespace std;
class Solution{
    using ll = long long;
public:  
    int closestCost(vector<int>& baseCosts,vector<int>& toppingCosts, int target){
        int n = baseCosts.size(), m = toppingCosts.size();
        ll ret = baseCosts[0], cur = 0;
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<(1<<m);j++){
                for(int k=0;k<(1<<m);k++){
                    cur = baseCosts[i];

                    for(int l =0 ;l<m;l++){
                        if(j & (1<<l)) cur += toppingCosts[l];
                        if(k & (1<<l)) cur += toppingCosts[l];
                    }
                    if(abs(ret - target) > abs(cur-target)){
                        ret = cur;
                    }else if(abs(ret - target) == abs(cur_target)){
                        ret = min(ret, cur);
                    }
                }
            }
        }
        return ret;
    }
};