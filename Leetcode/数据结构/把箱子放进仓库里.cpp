#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = boxes.size(), m = warehouse.size();
        vector<int> l(m), r(m);
        l[0] = r[m - 1] = INF;
        for (int i = 1; i < m; ++i)
            l[i] = min(l[i - 1], warehouse[i - 1]);
        for (int i = m - 2; i >= 0; --i)
            r[i] = min(r[i + 1], warehouse[i + 1]);
        for (int i = 0; i < m; ++i)
            warehouse[i] = min(warehouse[i], max(l[i], r[i]));
        sort(boxes.begin(), boxes.end());
        sort(warehouse.begin(), warehouse.end());
        int ans = 0, idx = 0;
        for (int box : boxes) {
            while (idx < m && warehouse[idx] < box)
                idx++;
            if (idx == m)
                break;
            ans++;
            idx++;
        }
        return ans;
    }
};
