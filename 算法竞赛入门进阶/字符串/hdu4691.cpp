#include<bits/stdc++.h>
#define N 200010
#define LL long long
using namespace std;
 
char s[N];
int sa[N],t[N],t2[N],c[N],n,rak[N],height[N];
 
void build_sa(int m,char *s)
{
    int i,*x=t,*y=t2;
    for (i=0;i<m;i++)c[i]=0;
    for (i=0;i<n;i++)c[x[i]=s[i]]++;
    for (i=1;i<m;i++)c[i]+=c[i-1];
    for (i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for (int k=1;k<=n;k<<=1)
    {
        int p=0;
        for (i=n-k;i<n;i++)y[p++]=i;
        for (i=0;i<n;i++)if (sa[i]>=k)y[p++]=sa[i]-k;
        for (i=0;i<m;i++)c[i]=0;
        for (i=0;i<n;i++)c[x[y[i]]]++;
        for (i=0;i<m;i++)c[i]+=c[i-1];
        for (i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1; x[sa[0]]=0;
        for (i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        if (p>=n) break;
        m=p;
    }
}
 
void getheight()
{
    int i,j,k=0;
    for (i=0;i<n;i++)rak[sa[i]]=i;
    for (i=0;i<n;i++)
    {
        if (k)k--;
        if (!rak[i])continue;
        j=sa[rak[i]-1];
        while (s[i+k]==s[j+k])k++;
        height[rak[i]]=k;
    }
}
 
int f[N][20]={0};
 
int main()
{
    while (~scanf("%s",s))
    {
        n=strlen(s); s[n]='0'; n++;
        build_sa(200,s);
        getheight();
 
        for (int i=0;i<n;i++) f[i][0]=height[i];
        for (int j=1;(1<<j)<n;j++)
			for (int i=0;i<n;i++)if (i+(1<<(j-1)) <n)
                f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
 
        int q,k;
        LL  ans1,ans2,x,y,x1,y1,w;
        scanf("%d",&q);
        scanf("%lld%lld",&x1,&y1);
        ans1=y1-x1+1;
        ans2=y1-x1+3;
        for (int i=1;i<q;i++)
        {
            scanf("%lld%lld",&x,&y);
            ans1+=y-x+1;
            int t=rak[x1],tt=rak[x];
            if (t>tt)swap(t,tt);
            if (t+1==tt) w=height[tt];else
            if (t==tt)w=min(y-x,y1-x1);else
            {
                t++;
                k=(int) log2(tt-t);
                w=min(f[t][k],f[tt-(1<<k)+1][k]);
            }
            w=min(w,min(y1-x1,y-x));
            ans2+=2+y-x-w;
            do { w/=10; ans2++;} while (w);
            x1=x,y1=y;
        }
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}