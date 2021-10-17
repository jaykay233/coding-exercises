#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
const long long INF =0x7f7f7f7f7f7fll;
long long sa[N],Rank[N],rank2[N],height[N],cnt[N],*x,*y;
long long mxx[N];
void radix_sort(int n,int sz)
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
        cnt[ x[ y[i] ] ]++;
    for(int i=1;i<sz;i++)
        cnt[i] += cnt[i-1];
    for(int i=n-1;i>=0;i--)
        sa[ --cnt[ x[ y[i] ] ] ] = y[i];
}
void get_sa(char text[],int n,int sz=128)
{
    x = Rank, y = rank2;
    for(int i=0;i<n;i++)
        x[i] = text[i], y[i] = i;
    radix_sort(n,sz);
    for(int len=1;len<n;len<<=1)
    {
        int yid = 0;
        for(int i=n-len;i<n;i++)
            y[yid++] = i;
        for(int i=0;i<n;i++)
            if(sa[i] >= len)
                y[yid++] = sa[i] - len;
        radix_sort(n,sz);
        swap(x,y);
        x[ sa[0] ] = yid = 0;
        for(int i=1;i<n;i++)
        {
            if(y[ sa[i-1] ]==y[ sa[i] ] && sa[i-1]+len<n && sa[i]+len<n && y[ sa[i-1]+len ]==y[ sa[i]+len ])
                x[ sa[i] ] = yid;
            else
                x[ sa[i] ] = ++yid;
        }
        sz = yid + 1;
        if(sz >= n)
            break;
    }
    for(int i=0;i<n;i++)
        Rank[i] = x[i];
}

void get_height(char text[],int n)
{
    int k = 0;
    for(int i=0;i<n;i++)
    {
        if(Rank[i] == 0)
            continue;
        k = max(0,k-1);
        int j = sa[ Rank[i]-1 ];
        while(i+k<n && j+k<n && text[i+k]==text[j+k])
            k++;
        height[ Rank[i] ] = k;
    }
}
char ch[N];
long long nxt[N];
int main (void)
{
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {
        char aim;
        scanf(" %c",&aim);
        scanf("%s",ch);
        int len=strlen(ch);
        get_sa(ch,len);
        get_height(ch,len);
        long long ans=0;
        int mx=len;
        for(int i=len-1;i>=0;i--)
        {
            if(ch[i]==aim)
            {
                mx=i;
            }
            nxt[i]=mx;
        }
        printf("Case #%d: ",cas++);
        for(int i=0;i<len;i++)
        {
            ans+=len-max(nxt[sa[i]],sa[i]+height[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}