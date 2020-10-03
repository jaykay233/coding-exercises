#include <bits/stdc++.h>
using namespace std;

class Soluton{
public:  
    int findTheLongestSubstring(string S){
        int ans = 0;
        int n = S.size();
        vector<int> pos(1<<5,-1);
        pos[0] = 0;
        int status = 0;
        for(int i =0;i<S.size();i++){
            if(S[i]=='a')  
                status ^= 1<<0;
            else if(S[i]=='e')
                status ^= 1<<1;
            else if(S[i]=='i')
                status ^= 1<<2;
            else if(S[i]=='o')
                status ^= 1<<3;
            else if(S[i]=='u')
                status ^= 1<<4;
            if(~pos[status])
                ans = max(ans, i + 1 - pos[status]);
            else 
                pos[status] = i + 1;
        }
    }
}