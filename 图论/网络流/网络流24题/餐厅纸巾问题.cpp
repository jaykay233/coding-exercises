#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define re register
#define gc getchar()
#define ll long long
#define il inline
il ll read() {
    re ll x(0),f(1);
    re char ch=gc;
    while(ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=gc;
    }
    while(ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=gc;
    }
    return x*f;
}
inline ll min(ll a,ll b) {
    return a<b?a:b;
}
const ll INF=(1<<29),N=100010;
struct node {
    ll to,next,w,c;
} e[N];
ll h[N],cnt=1,n,s,t;
inline void add(ll u,ll v,ll w,ll c) {
    e[++cnt]=(node) {v,h[u],w,c},h[u]=cnt;
    e[++cnt]=(node) {u,h[v],0,-c},h[v]=cnt;
}
#define QXX(u) for(ll i=h[u],y;y=e[i].to,i;i=e[i].next)
ll dis[N],vis[N],pre[N],f[N],maxf,minc,m;

ll spfa() {
    for(ll i=1; i<=t; ++i) dis[i]=INF,vis[i]=0;
    std::queue<ll> q;
    while(!q.empty()) q.pop();
    q.push(s);
    vis[s]=1,dis[s]=0,pre[t]=-1,f[s]=INF;
    while(!q.empty()) {
        ll x=q.front();
        q.pop();
        vis[x]=0;
        QXX(x) {
            if(!e[i].w) continue;
            if(dis[y]>dis[x]+e[i].c) {
                dis[y]=dis[x]+e[i].c;
                f[y]=min(f[x],e[i].w);
                pre[y]=i;
                if(!vis[y]) vis[y]=1,q.push(y);
            }
        }
    }
    return pre[t]==-1?-1:f[t];
}
void dinic () {
    ll x,in,y;
    while ((in=spfa ())!=-1) {
        x=t;
        while (x!=s) {
            y=pre[x];
            e[y].w-=in;
            e[y^1].w+=in;
            x=e[y^1].to;
        }
        maxf+=in;
        minc+=in*dis[t];
    }
    cout<<minc<<endl;
}

int main() {

    scanf("%d",&n);
    s=0,t=2*n+1;
    for(ll i=1; i<=n; i++) {
        ll x=read();
        add(s,i,x,0);
        add(i+n,t,x,0);
    }
    ll m=read(),t1=read(),m1=read(),t2=read(),m2=read();
    for(ll i=1; i<=n; i++) {
        if(i+1<=n) add(i,i+1,INF,0);
        if(i+t1<=n) add(i,i+n+t1,INF,m1);
        if(i+t2<=n) add(i,i+n+t2,INF,m2);
        add(s,i+n,INF,m);
    }
    dinic();
    return 0;
}
