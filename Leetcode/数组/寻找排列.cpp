#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res = {1};
        if(s.empty()) return res;
        int asc = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='D')
                res.insert(res.begin()+asc,i+2);
            else{
                res.push_back(i+2);
                asc = i+1;
            }
        }
        return res;
    }  
};