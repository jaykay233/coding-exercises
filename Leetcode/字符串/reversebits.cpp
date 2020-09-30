#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int reverseBits(int num){
        if(num==-1) return 32;
        int ans = 0;
        int cnt = 0,pre = 0;
        unsigned int num2 = num;
        while(num2){
            if(num2&1)
                cnt++;
            else{
                ans = max(ans,pre+cnt+1);
                pre=cnt;
                cnt = 0;
            }
            num2>>=1;
        }
        ans = max(ans,pre+cnt+1);
        return ans;
    }
};