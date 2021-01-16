#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define seit set<Node_t>::iterator

struct Node_t {
  int l, r;
  Node_t(const int &il, const int &ir) : l(il), r(ir){}
  inline bool operator<(const Node_t &o) const { return l < o.l; }
};

inline bool split_(int x, const int &m, set<Node_t> &odt) {
    if (x > MAXN) return false;
    auto it = --odt.upper_bound((Node_t){x, 0}); 
    int l = it->l, r = it->r;
    if(x - l == m || r - x == m) return true; 
     odt.erase(it);
     if(x - 1 >= l) odt.insert(Node_t(l, x - 1));
    if(r >= x + 1) odt.insert(Node_t(x + 1, r));
    return false;
}

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(m > n) return -1;  
        if(n == m) return n;
        set<Node_t> odt;
        odt.insert(Node_t(1,n));    
        for(int i = n - 1; i >= 0; --i)  if(split_(arr[i], m, odt)) return i;
        return -1;
    }
};
