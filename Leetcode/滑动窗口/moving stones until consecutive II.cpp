//https://leetcode-cn.com/problems/moving-stones-until-consecutive-ii/solution/jie-ti-si-lu-by-owenzzz/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int mx = stones.back() - stones.front() + 1 - stones.size();
        int n = stones.size();
        int delta = min(stones[1]-stones[0]-1,stones[n-1]-stones[n-2]-1);
        mx -= delta;
        int j  =0;
        
        int mi = n;
        
        for(int i =0;i<stones.size();i++){
            while(j<i && (stones[i] - stones[j]+1 > n))
                j++;
            int cost = n - (i-j+1);
            if(i-j+1==n-1 && stones[i] - stones[j] + 1==n-1)
                cost = 2;
            mi = min(mi,cost);
        }
        return {mi,mx};
    }
};