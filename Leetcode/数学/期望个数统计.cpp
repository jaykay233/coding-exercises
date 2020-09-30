//https://leetcode-cn.com/problems/qi-wang-ge-shu-tong-ji/
//期望线性性
#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    int expectNumber(vector<int>& scores){
        unordered_set<int> s;
        for(int n:scores) s.insert(n);
        return s.size();
    }
};