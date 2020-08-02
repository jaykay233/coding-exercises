#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res =0 ,maxCnt= 0,start =0;
        vector<int> cnt(26,0);
        for(int i =0;i<s.size();i++){
            maxCnt = max(maxCnt,++cnt[s[i]-'A']);
            while(i-start+1-maxCnt>k){
                --cnt[s[start]-'A'];
                start++;
            }
            res = max(res,i-start+1);
        }
        return res;
    }
};