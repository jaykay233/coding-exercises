#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        if(n<=26){
            return string(1,'A' + n-1);
        }
        int t = (n-1)%26 + 1;
        string tmp = string(1,'A' + (t-1));
        return convertToTitle((n-1)/26) + tmp;
    }
};