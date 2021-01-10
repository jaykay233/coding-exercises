#include <bits/stdc++.h>
using namespace std;
class BrowserHistory {
public:
    int pos;
    int top;
    string history[5001];
    BrowserHistory(string homepage) : pos(-1), top(0) {
        visit(homepage);
    }
    
    void visit(string url) {
        pos ++;
        top = pos;
        history[top++] = url;
    }
    
    string back(int steps) {
        if(steps > pos) {
            steps = pos;
        }
        pos -= steps;
        return history[pos];
    }
    
    string forward(int steps) {
        steps = min(steps, top - pos - 1);
        pos += steps;
        return history[pos];
    }
};
