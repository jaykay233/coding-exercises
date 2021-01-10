#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,int> m;
    int total;
    Solution(int n, vector<int>& b) {
        int wlen = n - b.size();
        this->total = wlen;
        unordered_set<int> w;
        for (int i = wlen; i < n; i++) w.insert(i);
        for (int x : b) w.erase(x);
        auto wi = w.begin();
        for (int x : b)
            if (x < wlen)
                m[x] = *wi++;
    }
    
    int pick() {
        int k = random()%total;
        return m.count(k) ? m[k] : k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */