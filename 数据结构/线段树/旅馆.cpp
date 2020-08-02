#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define lt x<<1
#define rt x<<1|1
const int maxn = 50100*4;
const int inf = 0x3f3f3f3f;
int f[maxn],L[maxn],R[maxn];
int G[maxn];
int n;
void build(int x,int l,int r)
{
    int mid=(l+r)>>1;
    f[x]=L[x]=R[x]=r-l+1;
    G[x]=-1;
    if(l==r) return;
    build(lt,l,mid);
    build(rt,mid+1,r);
}
void up(int x,int l,int r)
{
    int mid=(l+r)>>1;
    f[x]=max(f[lt],f[rt]);
    f[x]=max(f[x],L[rt]+R[lt]);
    if(L[lt]==mid-l+1)
        L[x]=L[lt]+L[rt];
    else
        L[x]=L[lt];
    if(R[rt]==r-mid)
        R[x]=R[rt]+R[lt];
    else
        R[x]=R[rt];
}
void pushdown(int x,int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    G[lt]=G[rt]=G[x];
    if(G[x]){
        f[lt]=L[lt]=R[lt]=0;
        f[rt]=L[rt]=R[rt]=0;
    }else{
        f[lt]=L[lt]=R[lt]=mid-l+1;
        f[rt]=L[rt]=R[rt]=r-mid;
    }
    G[x]=-1;
}
int query(int x,int l,int r,int len)
{
    if(f[x]<len) return 0;
    if(G[x]!=-1) pushdown(x, l, r);
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(f[lt]>=len) return query(lt, l, mid, len);
    if(R[lt]+L[rt]>=len) return mid-R[lt]+1;
    return query(rt,mid+1,r,len);
    
}
void change(int x,int l,int r,int ll,int rr,int v)
{
    if(ll<=l&&rr>=r){
        G[x]=v;
        if(v==0){
            f[x]=L[x]=R[x]=r-l+1;
        }else{
            f[x]=L[x]=R[x]=0;
        }
    }
    else{
        if(G[x]!=-1) pushdown(x,l,r);
        int mid=(l+r)>>1;
        if(ll<=mid){
            change(lt, l, mid, ll, rr, v);
        }
        if(mid+1<=rr){
            change(rt,mid+1,r,ll,rr,v);
        }
        up(x,l,r);
    }
}
int main()
{
    int m;
    while(~scanf("%d %d",&n,&m)){
        build(1,1,n);
        for(int i=1;i<=m;i++){
            int k;scanf("%d",&k);
            if(k==1){
                int len;scanf("%d",&len);
                int ans=query(1,1,n,len);
                printf("%d\n",ans);
                if(ans!=0){
                    change(1,1,n,ans,ans+len-1,1);
                }
            }else{
                int l,len;
                scanf("%d %d",&l,&len);
                change(1,1,n,l,l+len-1,0);
            }
        }
    }
}
