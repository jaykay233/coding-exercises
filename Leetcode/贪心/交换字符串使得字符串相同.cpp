#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int len = s1.size(), xy=0,yx = 0;
        for(int i =0;i<len;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i]=='x') xy++;
            else yx++;
        }
        return ((xy + yx) & 1) == 1 ? -1 : (xy + 1) / 2 + (yx + 1) / 2;
    }
};