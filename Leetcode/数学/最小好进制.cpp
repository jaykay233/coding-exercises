#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class Solution{
public:  
    string smallestGoodBase(string N){
        LL n =stoll(N);
        LL ans = n-1;
        for(int s=59;s>=2;s--){
            int k = pow(n,1.0/s);
            if(k>1){
                LL sum = 1,mul=1;
                for(int i=1;i<=s;i++){
                    mul*=k;
                    sum += mul;
                }
                if(sum==n){
                    ans =k;
                    break;
                }
            }
        }
        return to_string(ans);
    }
};