#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = key.size();
        int m = ring.size();
        int f[n][m];
        memset(f,0x3f,sizeof f);
        for(int i=0;i<m;i++){
            if(ring[i]==key[0]){
                f[0][i] = min(i,m-i) + 1;
            }
        }
        

        for(int i=1;i<n;i++){
            for(int j =0;j<m;j++){
                if(f[i-1][j]==0x3f3f3f3f) continue;
                for(int k=0;k<m;k++){
                    if(ring[k]!=key[i]) continue;
                    int t1 = abs(k-j);
                    int t2 = m - t1;
                    f[i][k] = min(f[i][k],f[i-1][j] + min(t1,t2) + 1);
                }
            }
        }
        int min_val = 0x3f3f3f3f;
        for(int i =0;i<m;i++){
            min_val = min(min_val,f[n-1][i]);
        }
        return min_val;
    }
};