#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr =0, n = s.size(), last =0, ans =0;
        while(ptr<n){
            char c = s[ptr];
            int count =0;
            while(ptr<n && s[ptr]==c){
                ++ptr;
                ++count;
            }
            ans+=min(count,last);
            last = count;
        }
        return ans;
    }
};