#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
const int Mod = 1e9 + 7;
char s[maxn];
int bits[maxn];
ll dp[maxn][10][2][2];

ll dfs(int pos,bool lead,bool flag1,bool flag2,int pre,bool flag){
    if(pos<0) {
        if(lead && pre==0) return 0;
        return 1;
    }
    if(!flag && !lead && dp[pos][pre][flag1][flag2]!=-1) return dp[pos][pre][flag1][flag2];
    int up = flag?bits[pos]:9; ll ret =0 ;
    for(int i =0;i<=up;i++){
        if(flag2 && i>=pre) ret = (ret + dfs(pos-1,lead && i==0, flag1,flag2,i, flag && i==up)) % Mod;
        else if(flag1 && !flag2) 
            ret = (ret + dfs(pos-1,lead && i==0, flag1,i>pre?true:false,i,flag && i==up)) % Mod;
        else if(!flag1 && !flag2){
            bool t1 = false,t2 = false;
            if(!lead && i>pre) t2 = true;
            else if(!lead && i<pre) t1 = true;
            ret = (ret + dfs(pos-1,lead && i==0,t1,t2,i,flag && i==up)) % Mod;
        }
    }
    if(!lead && !flag) dp[pos][pre][flag1][flag2] = ret;
    return ret;
}

ll calc(){
    int len = 0;
    for(int i=strlen(s)-1;i>=0;i--)
        bits[len++] = s[i] - '0';
    return dfs(len-1,true,false,false,-1,true);
}

int main(){
    memset(dp,-1,sizeof dp);
    int T,N;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%s",s);
        printf("%lld\n",calc());
    }
    return 0;
}