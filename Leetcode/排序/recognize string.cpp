#include <bits/stdc++.h>
using namespace std;

class Solution{
    string recognizeString(string S){
        string res = "";
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> q;
        for(char c:S) ++m[c];
        for(auto a:m){
            if(a.second > (S.size()+1)/2) return "";
            q.push({a.second,a.first});
        }
        while(q.size()>=2){
            auto t1 = q.top();q.pop();
            auto t2 = q.top();q.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if(--t1.first>0) q.push(t1);
            if(--t2.first>0) q.push(t2);
        }
        if(q.size()>0) res.push_back(q.top().second);
        return res;
    }
};