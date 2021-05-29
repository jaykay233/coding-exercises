#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int countSubstrings(string s){
        string t = "#";
        for(int i =0;i<s.size();i++){
            t+=s[i];
            t+='#';
        }
        int ans = 0;
        int n = t.size();
        vector<int> rl(n);
        int mx =0 ;
        int pos = 0;
        int ml =0 ;
        string sub = "";
        for(int i=1;i<n;i++){
            if(i<=mx){
                rl[i] = min(rl[2*pos - i],mx-i);
            }else rl[i] = 1;
            while(i-rl[i]>=0 && i+rl[i]<n && t[i-rl[i]]==t[i+rl[i]]) rl[i]++;
            if(i+rl[i]-1>mx){
                mx=  i + rl[i] - 1;
                pos = i;
            }
            ans += (rl[i]/2);
        }
        return ans;
    }
};