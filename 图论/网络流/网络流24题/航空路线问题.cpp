//minamoto
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#define inf 0x3f3f3f3f
using namespace std;
const int N=5005,M=500005;
int ver[M],Next[M],head[N],edge[M],flow[M],tot=1;
int dis[N],disf[N],Pre[N],last[N],vis[N],maxflow,maxcost;
int n,m,s,t;bool check=0;
queue<int> q;
map<string,int> mp;
string name[N];
inline void add(int u,int v,int f,int e){
    ver[++tot]=v,Next[tot]=head[u],head[u]=tot,flow[tot]=f,edge[tot]=e;
    ver[++tot]=u,Next[tot]=head[v],head[v]=tot,flow[tot]=0,edge[tot]=-e;
}
bool spfa(){
    memset(dis,0xef,sizeof(dis));
    q.push(s),dis[s]=0,disf[s]=inf,Pre[t]=-1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=Next[i]){
            int v=ver[i];
            if(flow[i]&&dis[v]<dis[u]+edge[i]){
                dis[v]=dis[u]+edge[i],last[v]=i,Pre[v]=u;
                disf[v]=min(disf[u],flow[i]);
                if(!vis[v]) vis[v]=1,q.push(v);
            }
        }
    }
    return ~Pre[t];
}
void dinic(){
    while(spfa()){
        int u=t;maxflow+=disf[t],maxcost+=disf[t]*dis[t];
        while(u!=s){
            flow[last[u]]-=disf[t];
            flow[last[u]^1]+=disf[t];
            u=Pre[u];
        }
    }
}
int ans[1005];int num=0;
void out(int u){
    ans[++num]=u;
    for(int i=head[u];i;i=Next[i]){
        if(flow[i]==0&&edge[i]>=0){
            out(ver[i]);
            flow[i]=1;
            return;
        }
    }
}
int main(){
    //freopen("testdata.in","r",stdin);
    string s1,s2;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        cin>>s1;
        mp[s1]=i;
        name[i]=s1;
        add(i,i+n,1,1);
    }
    for(int i=1;i<=m;++i){
        cin>>s1>>s2;
        int a=mp[s1],b=mp[s2];
        if(a>b) swap(a,b);
        if(a==1&&b==n) check=1;
        add(a+n,b,1,1);
    }
    add(1,n+1,1,1),add(n,n+n,1,1);
    s=1,t=n+n;
    dinic();
    if(!maxflow||(maxflow==1&&!check)) return puts("No Solution!"),0;
    if(maxflow==1&&check){cout<<2<<'\n'<<name[1]<<'\n'<<name[n]<<'\n'<<name[1]<<'\n';return 0;}
    printf("%d\n",maxcost/2-1);
    //这里的最多城市数是这个
    //因为考虑如果边连成一个环，边数等于点数
    //然后每个点拆成两个，除以二
    //然后因为s'和t'被重复了两次，减去1 
    out(s);
    for(int i=1;i<=num;++i) if(ans[i]<=n) cout<<name[ans[i]]<<'\n';
    num=0;
    out(s);
    for(int i=num-2;i;--i) if(ans[i]<=n) cout<<name[ans[i]]<<'\n';
    //最后两个肯定是t和t'，不用管 
    return 0;
}