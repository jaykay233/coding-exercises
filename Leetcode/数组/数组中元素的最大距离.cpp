#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& list) {
        int res = 0, min_val = list[0][0], max_val = list[0][list[0].size() - 1];
        for (int i = 1; i < list.size(); i++) {
            res = max(res, max(abs(list[i][list[i].size() - 1] - min_val), abs(max_val - list[i][0])));
            min_val = min(min_val, list[i][0]);
            max_val = max(max_val, list[i][list[i].size() - 1]);
        }
        return res;
    }
};