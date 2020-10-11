/*
    multiset乱搞一下
    需要注意multiset只有双向迭代器，需要用std::next来求中位数
    时间复杂度大概是 O((n-k)*max(lg(k),k)),其实就是 O((n-k)*k)
*/
//乱搞法
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double>all(nums.begin(),nums.begin()+k);
        vector<double>res;
        double val = (*next(all.begin(),k/2) + *next(all.begin(),(k-1)/2))*0.5;
        res.push_back(val);
        int n = nums.size();
        for ( int i = k ; i < n ; i++){
            auto it = all.find(nums[i-k]);
            all.erase(it);
            all.insert(nums[i]);
            val = (*next(all.begin(),k/2) + *next(all.begin(),(k-1)/2))*0.5;
            res.push_back(val);
        }
        return res;
    }
};
