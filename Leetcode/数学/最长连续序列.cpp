#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // cnt用于记录当前集合的元素个数
    unordered_map<int,int> uf, cnt;

    int find(int i){
        return i == uf[i] ? i: uf[i] = find(uf[i]);
    }

    int merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return cnt[x];
        uf[y] = x;
        //更新合并之后的连通分量的元素个数
        cnt[x] += cnt[y];
        return cnt[x];
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i: nums) uf[i] = i, cnt[i] = 1;
        int ans = 1;
        for(int i: nums){
            if(i != INT_MAX && uf.count(i+1)) ans = max(ans, merge(i, i+1));
        }
        return ans;
    }
};

