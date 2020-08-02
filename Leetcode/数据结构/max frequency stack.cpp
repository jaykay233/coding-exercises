#include <bits/stdc++.h>
using namespace std;
class FreqStack{
private: 
    int mxfreq;
    unordered_map<int,int> freq;
    unordered_map<int,vector<int>> m;
public:
    FreqStack(){}

    void push(int x){
        mxfreq = max(mxfreq,++freq[x]);
        m[freq[x]].push_back(x);
    }

    int pop(){
        int x = m[mxfreq].back();
        m[mxfreq].pop_back();
        if(m[freq[x]--].empty()) mxfreq--;
        return x;
    }
};