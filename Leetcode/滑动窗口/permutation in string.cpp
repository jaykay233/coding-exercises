#include <bits/stdc++.h>
using namespace std;
//典型题目
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        deque<int> dq;
        unordered_map<char,int> m;
        for(char c:s1){
            m[c]++;
        }
        int n1 = s1.size();
        int n2 = s2.size();
        unordered_map<char,int> m2;
        int cnt= 0 ;
        for(int i =0;i<n2;i++){
            while(!dq.empty() && dq.front()<=i-n1) {
                int val = m2[s2[dq.front()]];
                if(m.count(s2[dq.front()]) && val>=1 && val<=m[s2[dq.front()]]) cnt--;
                m2[s2[dq.front()]]--;
                dq.pop_front();
            }
            dq.push_back(i);
            m2[s2[i]]++;
            if(m2[s2[i]]>=1 && m2[s2[i]]<=m[s2[i]]) cnt++;
            if(cnt == n1) return true;
        }
        return false;
    }
};