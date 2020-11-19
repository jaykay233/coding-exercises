#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min_ = A[0], max_ = A[0];
        for (int x: A) {
            min_ = min(min_, x);
            max_ = max(max_, x);
        }
        return max(0, max_ - min_ - 2*K);
    }
};