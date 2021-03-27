#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int dig[20];
ll p[25];
struct sta{
   ll cnt,sum,sqsum;
   sta(){cnt=-1;sum=sqsum=0;}
   sta(ll cnt,ll sum,ll sqsum):cnt(cnt),sum(sum),sqsum(sqsum){}
}dp[20][10][10];

void init(){
   p[1]=1;
   for(int i=2;i<=20;i++) p[i]=(p[i-1]*10)%mod;
}

sta dfs(int pos,int pre1,int pre2,bool limit){
    if(pos<1) return pre1%7!=0&&pre2%7!=0? sta(1,0,0):sta(0,0,0);
    if(!limit&&dp[pos][pre1][pre2].cnt!=-1) return dp[pos][pre1][pre2];
    int ed=limit ? dig[pos] : 9;
    sta ans;ans.cnt=0;
    for(int i=0;i<=ed;i++){
       if(i==7) continue;
       sta next=dfs(pos-1,(pre1+i)%7,(pre2*10+i)%7,limit&&i==ed);
       ans.cnt=(ans.cnt+next.cnt)%mod;
       ans.sum=(ans.sum+next.sum+(p[pos]*i)%mod*next.cnt)%mod;
       ans.sqsum=(ans.sqsum+next.sqsum)%mod;
       ans.sqsum=(ans.sqsum+(2*p[pos]*i)%mod*next.sum%mod)%mod;
       ans.sqsum=(ans.sqsum+(next.cnt*p[pos])%mod*p[pos]%mod*i*i%mod)%mod;
    }
    if(!limit) dp[pos][pre1][pre2]=ans;
    return ans;
}

ll sol(ll x){
   int t=0;
   while(x){
      dig[++t]=x%10;
      x/=10;
   }
   return dfs(t,0,0,true).sqsum;
}

int main(){
   init();
   int T;scanf("%d",&T);
   while(T--){
      ll l,r;scanf("%lld%lld",&l,&r);
      ll ans=sol(r);
      ans-=sol(l-1);
      printf("%lld\n",(ans%mod+mod)%mod);
   }
}
