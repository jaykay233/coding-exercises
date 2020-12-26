#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int balancedString(string s) {
        int len = s.size();
        unordered_map<int,int> cnt;
        for(char c:s){
            cnt[c-'A']++;
        }
        int m = len/4;
        int l =0;
        int res = INT_MAX/2;
        for(int r = 0;r<len;r++){
            cnt[s[r]-'A']--;
            while(l<len && cnt['Q'-'A']<=m && cnt['W'-'A']<=m && cnt['E'-'A']<=m && cnt['R'-'A']<=m){
                res = min(res,r-l+1);
                cnt[s[l++]-'A']++;
            }
        }
        return res;
    }
};