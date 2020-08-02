#include <bits/stdc++.h>
using namespace std;
class Solution{
public:     
    string removeDuplicateLetters(string s){
        int m[256] = {0};
        int visted[256] ={0};
        string res = "0";
        for(auto a:s) m[a]++;
        for(auto a:s){
            --m[a];
            if(visted[a]) continue;
            while(a<res.back() && m[res.back()]){
                visted[res.back()]=0;
                res.pop_back();
            }
            res+=a;
            visted[a] = 1;
        }
        return res.substr(1);
    }
};