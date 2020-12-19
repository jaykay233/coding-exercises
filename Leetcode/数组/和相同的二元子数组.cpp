#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int N = A.size();
        vector<int> P(N+1);
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        unordered_map<int,int> count;
        int ans = 0;
        for (int x: P) {
            ans += count[x-S];
            count[x]++;
        }

        return ans;

    }
};