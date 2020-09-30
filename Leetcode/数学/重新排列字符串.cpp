#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    string restoreString(string s,vector<int>& indices){
        int length = s.size();
        for(int i =0;i<length;i++){
            if(indices[i]!=i){
                char ch = s[i];
                int idx = indices[i];
                while(idx!=i){
                    swap(s[idx],ch);
                    swap(indices[idx],idx);
                }
                s[i]=ch;
                indices[i]=i;
            }
        }
        return s;
    }
};