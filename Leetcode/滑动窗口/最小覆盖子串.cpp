#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        int cnt =0;
        for(char c:t) {
            m[c]++;
            cnt++;
        }
        int minlen = INT_MAX;
        int l = 0;
        int minidx=0;
        for(int i =0;i<s.size();i++){
            m[s[i]]--;
            if(m[s[i]]>=0) cnt--;
            while(cnt==0){
                // minlen = min(minlen,i-l+1);
                if(i-l+1<minlen){
                    minlen = i-l+1;
                    minidx = l;
                }
                m[s[l]]++;
                if(m[s[l]]>0) cnt++;
                l++;
            }
        }
        if(minlen==INT_MAX) return "";
        return s.substr(minidx,minlen);
    }
};

