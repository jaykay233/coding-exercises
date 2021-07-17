#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    unordered_map<int,int> a,b;
    int find(int x){
        return a.count(x) ? a[x] = find(a[x]) : x;
    }

    int longestConsecutive(vector<int>& nums){
        for(auto i:nums)
            a[i] = i + 1;
        int ans =0 ;
        for(auto i : nums){
            int y = find(i+1);
            ans = max(ans, y - i);
        }
        return ans;
    }
};