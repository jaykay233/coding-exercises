#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) { // 注意原题这里是小k，为了和题解中的符号一致，输入改为大K
        int N = nums.size();
        vector<int> W(N - K + 1, 0);

        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += nums[i];
            if (i >= K) { sum -= nums[i - K]; }
            if (i >= K - 1) { W[i - K + 1] = sum; }
        }

        vector<int> left(W.size(), 0);
        int best = 0;
        for (int i = 0; i < W.size(); ++i) {
            if (W[i] > W[best]) { best = i; } // 注意这里是 >，为了输出是字典序列
            left[i] = best;
        }

        vector<int> right(W.size(), 0);
        best = W.size() - 1;
        for (int i = W.size() - 1; i >= 0; --i) {
            if (W[i] >= W[best]) { best = i; } // 注意这里是 >=，为了输出是字典序列
            right[i] = best;
        }

        vector<int> ans{-1, -1, -1};
        for (int j = K; j < W.size() - K; ++j) {
            int i = left[j - K], k = right[j + K];
            if (ans[0] == -1 || W[i] + W[j] + W[k] > 
                    W[ans[0]] + W[ans[1]] + W[ans[2]]) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = k;
            }
        }
        return ans;
    }
};