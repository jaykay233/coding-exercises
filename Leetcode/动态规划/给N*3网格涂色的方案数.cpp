#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    const int mod=1e9+7;
    int numOfWays(int n){
        vector<int> types;
        for(int i =0;i<3;i++){
            for(int j =0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(i!=j && j!=k){
                        if(i!=j && j!=k){
                            types.push_back(i*9 + j*3 + k);
                        }
                    }
                }
            }
        }

        int type_cnt = types.size();
        vector<vector<int>> related(type_cnt,vector<int>(type_cnt));
        
        for (int i = 0; i < type_cnt; ++i) {
            int x1 = types[i] / 9, x2 = types[i] / 3 % 3, x3 = types[i] % 3;
            for (int j = 0; j < type_cnt; ++j) {
                int y1 = types[j] / 9, y2 = types[j] / 3 % 3, y3 = types[j] % 3;
                if (x1 != y1 && x2 != y2 && x3 != y3) {
                    related[i][j] = 1;
                }
            }
        }


        vector<vector<int>> f(n+1,vector<int>(type_cnt));
        for(int i =0;i<type_cnt;i++)
            f[1][i] = 1;    
        for(int i=2;i<=n;i++){
            for(int j=0;j<type_cnt;j++){
                for(int k =0;k<type_cnt;k++){
                    if(related[k][j]){
                        f[i][j] += f[i-1][k];
                        f[i][j] %= mod;
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i =0;i<type_cnt;i++){
            ans += f[n][i];
            ans %= mod;
        }
        return ans;
    }
};