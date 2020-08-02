#include <bits/stdc++.h>
using namespace std;
//思维题
class Solution {
public:
    bool canConvert(string str1, string str2) {
        map<char,char> change;
        set<char> have;
        for(int i =0;i<str1.size();i++){
            have.insert(str2[i]);
            if(!change.count(str1[i])) change[str1[i]] = str2[i];
            if(change[str1[i]]!=str2[i]) return false;
        }
        return change.size() >= have.size() && (have.size()<26 || str1==str2);
    }
};