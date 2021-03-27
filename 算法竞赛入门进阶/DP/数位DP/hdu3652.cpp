#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 13;
ll dp[20][3][13];
int dis[20];

ll dfs(int len,int type,int mod,bool flag){
    if(len<0) return type==2 && mod ==0;
    if(!flag && dp[len][type][mod]!=-1) return dp[len][type][mod];
    int end = flag?dis[len]:9;
    int ans = 0;
    for(int i=0;i<=end;i++){
        if(type==2 || (type==1 && i==3))
            ans += dfs(len-1,2,(mod*10+i)%MOD, flag && i==end);
    }
}


int main(){


    return 0;
}