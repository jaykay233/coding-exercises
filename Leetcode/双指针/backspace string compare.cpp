#include <bits/stdc++.h>
using namespace std;
//反向比较
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = "";
        int skip = 0;
        for(int i = S.size()-1;i>=0;i--){
            if(S[i]=='#') skip++;
            else if(skip){
                skip--;
            }else s+=S[i];
        }
        
        string t= "";
        skip =0 ;
        for(int i =T.size()-1;i>=0;i--){
            if(T[i]=='#') skip++;
            else if(skip){
                skip--;
            }else t+=T[i];
        }
        return s == t;
        
    }
};