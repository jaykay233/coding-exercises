#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define INF 0x3f3f3f3f
#define LL long long
#define bug cout<<"bug"<<endl
const int MAXN = 1007;
const int MAXM = 20007;
const int MOD = 1e9 + 9;
using namespace std;
int num[MAXN];
int ans[MAXN];
int gcd(int x, int y)
{
    if(x==0)return y;
    return gcd(y%x,x);
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&num[i]);
            for(int j=0; j<i; ++j)
                ans[gcd(num[j],num[i])]=1;
        }
        int flag=1,cnt=n;
        while(flag && cnt>3)
        {
            cnt--;
            flag=0;
            for(int i=1; i<=1000; ++i)
            {
                if(ans[i])
                    for(int j=0; j<n; ++j)
                    {
                        int poi=gcd(i,num[j]);
                        if(!ans[poi])
                        {
                            flag=1;
                            ans[poi]=1;
                        }
                    }
            }
        }
        int p=1;
        for(int i=1; i<1001; ++i)
        {
            if(ans[i])
            {
                if(p)printf("%d",i),p--;
                else printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
