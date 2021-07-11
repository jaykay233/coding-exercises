//https://leetcode.com/problems/valid-parenthesis-string/solution/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int high = 0;
        int low = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='(') {
                high++;
                low++;
            }else if(s[i]==')'){
                high--;
                low--;
            }else if(s[i]=='*'){
                high++;
                low--;
            }
            if(high<0) return false;
            low = max(low,0);
        }
        return low == 0;
    }
};