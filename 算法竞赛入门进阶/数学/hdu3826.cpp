#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

ll prime[1000086];
ll cnt,t,n;
int maxx=1e6+5;
bool vis[1000086];


void init()
{
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false;
    cnt=0;
    for(ll i=2;i<=maxx;i++)
    {
        if(vis[i])
            prime[cnt++]=i;
        for(ll j=0;j<cnt && i*prime[j]<=maxx;j++)
        {
            vis[ i*prime[j] ]=false;
            if( i%prime[j]==0 ) break;
        }
    }
}

int main()
{
    init();
    scanf("%lld",&t);
    for(ll k=1;k<=t;k++)
    {
        bool flag=false;
        scanf("%lld",&n);
        for(ll i=0;i<cnt && !flag;i++)
        {
            int num=0;
            while( n%prime[i]==0 )///分解质因子
            {
                n=n/prime[i];
                num++;
            }
            if(num>=2)
            {
                flag=true;
                break;
            }
        }
        /*分解完所有小于10^6的质因子，出来后的这个n还大于1的有三种情况
        第一种情况，是一个 大于10^6 的素数
        第二种情况，是两个 大于10^6 的素数 的乘积，不可能还有第三个大于10^6的质因子
        第三种情况，是一个 大于10^6 的素数 的平方，不可能还有第三个大于10^6的质因子
        */
        if(!flag && n>1)
        {
            ll temp=(ll)sqrt(n);
            if(temp*temp==n)
                flag=true;
        }
        if(flag)
            printf("Case %lld: No\n",k);
        else
            printf("Case %lld: Yes\n",k);
    }
    return 0;
}