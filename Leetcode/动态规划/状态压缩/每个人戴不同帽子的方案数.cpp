#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    const int mod = 1e9+7;
    int numberWays(vector<vector<int>>& hats){
        int n =hats.size();
        int maxhat= 0 ;
        for(vector<int>& hat:hats){
            for(int j:hat)
                maxhat=max(maxhat,j);
        }
        vector<vector<int>> hatToPerson(maxhat+1);
        for(int i=0;i<n;i++){
            for(int h:hats[i])
                hatToPerson[h].push_back(i);
        }

        vector<vector<int>> f(maxhat+1,vector<int>(1<<n));
        f[0][0]=1;
        for(int i=1;i<=maxhat;i++){
            for(int mask=0;mask<(1<<n);mask++){
                f[i][mask] = f[i-1][mask];
                for(int j:hatToPerson[i]){
                    if(mask & (1<<j)){
                        f[i][mask] += f[i-1][mask ^ (1<<j)];
                        f[i][mask] %= mod;
                    }
                }
            }
        }
        return f[maxhat][(1<<n)-1];
    }
};