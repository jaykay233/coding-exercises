#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    bool winnerSquareGame(int n){
        vector<bool> f(n+1);
        f[0] = false;
        for(int i=1;i<=n;i++){
            for(int k=1;k*k<=i;k++){
                if(!f[i-k*k]){
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};