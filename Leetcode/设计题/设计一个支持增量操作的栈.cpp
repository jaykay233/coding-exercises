#include <bits/stdc++.h>
using namespace std;
class CustomStack {
public:
    vector<int> stk, add;
    int top;

    CustomStack(int maxSize) {
        stk.resize(maxSize);
        add.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if (top != stk.size() - 1) {
            ++top;
            stk[top] = x;
        }
    }
    
    int pop() {
        if (top == -1) {
            return -1;
        }
        int ret = stk[top] + add[top];
        if (top != 0) {
            add[top - 1] += add[top];
        }
        add[top] = 0;
        --top;
        return ret;
    }
    
    void increment(int k, int val) {
        int lim = min(k - 1, top);
        if (lim >= 0) {
            add[lim] += val;
        }
    }
};
