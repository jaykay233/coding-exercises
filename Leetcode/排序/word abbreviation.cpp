#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<int> pre(n,1);
        vector<string> res(n);
        for(int i =0;i<n;i++)
            res[i] = abbreviate(dict[i],pre[i]);
        for(int i =0;i<n;i++){
            while(true){
                unordered_set<int> st;
                for(int j =i+1;j<n;j++){
                    if(res[i]==res[j])
                        st.insert(j);
                }
                if(st.empty()) break;
                st.insert(i);
                for(int t:st)
                    res[t] = abbreviate(dict[t],++pre[t]);    
            }
        }
        return res;
    }
    
    string abbreviate(string s,int k){
        return k>=s.size()-2?s:s.substr(0,k) + to_string(s.size()-k-1) + s.back();
    }
};