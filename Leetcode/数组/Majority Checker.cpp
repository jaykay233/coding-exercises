//https://leetcode.com/problems/online-majority-element-in-subarray/discuss/618534/C%2B%2B-Several-solutions.
#include <bits/stdc++.h>
using namespace std;
//binary search + segment tree
class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) : arr(arr) {
        if (arr.size() == 0) return ;
        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(arr[i]) == mp.end()) mp[arr[i]] = vector<int>(1, i);
            else mp[arr[i]].push_back(i);
        }
        node.resize(4 * arr.size(), -1);
        build(0, arr.size() - 1, 1);
    }
    
    int query(int left, int right, int threshold) {
        // index, occur
        pair<int, int> ret = query(left, right, 0, arr.size() - 1, 1);
        if (ret.second >= threshold) return ret.first;
        else return -1;
    }
private:
    void build(int st, int ed, int cur) {
        if (st == ed) {
            node[cur] = arr[st];
            return ;
        }
        int mid = (st + ed) / 2;
        build(st, mid, cur * 2);
        build(mid + 1, ed, cur * 2 + 1);
        if (node[cur * 2] != -1 && count_occur(node[cur * 2], st, ed) * 2 > ed - st + 1) {
            node[cur] = node[cur * 2];
        }
        else if (node[cur * 2 + 1] != -1 && count_occur(node[cur * 2 + 1], st, ed) * 2 > ed - st + 1) {
            node[cur] = node[cur * 2 + 1];
        }
        return ;
    }

    pair<int, int> query(const int &l, const int &r, int st, int ed, int cur) {
        if (st > r || ed < l) {
            return make_pair(-1, -1);
        }
        if (l <= st && ed <= r) {
            if (node[cur] == -1) return make_pair(-1, -1);
            int occ = count_occur(node[cur], l, r);
            if (occ * 2 > r - l + 1) return make_pair(node[cur], occ);
            else return make_pair(-1, -1);
        }
        int mid = (st + ed) / 2;
        if (l <= mid) {
            pair<int, int> ret_l = query(l, r, st, mid, cur * 2);
            if (ret_l.first != -1) return ret_l;
        }
        if (r > mid) {
            pair<int, int> ret_r = query(l, r, mid + 1, ed, cur * 2 + 1);
            if (ret_r.first != -1) return ret_r;
        }
        return make_pair(-1, -1);
    }

    int count_occur(int val, int left, int right) {
        int st_idx = lower_bound(mp[val].begin(), mp[val].end(), left)
                - mp[val].begin();
        int ed_idx = upper_bound(mp[val].begin(), mp[val].end(), right)
                - mp[val].begin();
        return ed_idx - st_idx;
    }

    unordered_map<int, vector<int>> mp;
    vector<int> arr, node;
};