#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int ans = 0;
        for(int i = 0;i<A.size();i++){
            ans = ans * 2 + A[i];
            ans%=5;
            if(ans==0) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};