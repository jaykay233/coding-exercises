#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0, n = row.size();
        for (int i = 0; i < n; i += 2) {
            if (row[i + 1] == (row[i] ^ 1)) continue;
            ++res;
            for (int j = i + 1; j < n; ++j) {
                if (row[j] == (row[i] ^ 1)) {
                    row[j] = row[i + 1];
                    row[i + 1] = row[i] ^ 1;
                    break;
                }
            }
        }
        return res;
    }
};