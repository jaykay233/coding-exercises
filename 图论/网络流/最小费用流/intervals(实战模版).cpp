#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
#define LL long long
#define pa pair<int,int>
#define maxn 1000
#define maxm 1000
#define inf 1000000000
using namespace std;
int tt,n,k,s,t,cnt,ans,tot;
int head[maxn],dis[maxn],p[maxn],a[maxn],b[maxn],w[maxn],f[maxn];
bool inq[maxn];
map<int,int> mp;
struct edge_type
{
	int from,to,next,v,c;
}e[maxm];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void add_edge(int x,int y,int v,int c)
{
	e[++cnt]=(edge_type){x,y,head[x],v,c};head[x]=cnt;
	e[++cnt]=(edge_type){y,x,head[y],0,-c};head[y]=cnt;
}
inline bool spfa()
{
	queue<int>q;
	memset(inq,false,sizeof(inq));
	F(i,1,t) dis[i]=inf;
	dis[s]=0;q.push(s);inq[s]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();inq[x]=false;
		for(int i=head[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if (e[i].v&&dis[y]>dis[x]+e[i].c)
			{
				dis[y]=dis[x]+e[i].c;
				p[y]=i;
				if (!inq[y]){q.push(y);inq[y]=true;}
			}
		}
	}
	return dis[t]!=inf;
}
inline void mcf()
{
	ans=0;
	while (spfa())
	{
		int tmp=inf;
		for(int i=p[t];i;i=p[e[i].from]) tmp=min(tmp,e[i].v);
		ans+=tmp*dis[t];
		for(int i=p[t];i;i=p[e[i].from]){e[i].v-=tmp;e[i^1].v+=tmp;}
	}
}
int main()
{
	tt=read();
	while (tt--)
	{
		memset(head,0,sizeof(head));
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		cnt=1;tot=0;
		n=read();k=read();
		F(i,1,n)
		{
			a[i]=read();b[i]=read();w[i]=read();
			f[2*i-1]=a[i];f[2*i]=b[i];
		}
		sort(f+1,f+2*n+1);
		F(i,1,2*n) if (i==1||f[i]!=f[i-1]) mp[f[i]]=++tot;
		s=tot+1;t=tot+2;
		F(i,1,tot-1) add_edge(i,i+1,k,0);
		add_edge(s,1,k,0);add_edge(tot,t,k,0);
		F(i,1,n) add_edge(mp[a[i]],mp[b[i]],1,-w[i]);
		mcf();
		printf("%d\n",-ans);
	}
}