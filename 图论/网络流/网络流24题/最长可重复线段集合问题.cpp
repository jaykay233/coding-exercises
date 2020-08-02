#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10,inf=0xcfcfcfcf,INF=0x3f3f3f3f;

char buf[1<<15],*fs,*ft;
inline char getc() { return (ft==fs&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),ft==fs))?0:*fs++; }
template<typename T>inline void read(T &x)
{
    x=0;
    T f=1, ch=getchar();
    while (!isdigit(ch) && ch^'-') ch=getchar();
    if (ch=='-') f=-1, ch=getchar();
    while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
    x*=f;
}

template<typename T>inline void write(T x)
{
    if (!x) { putchar('0'); return ; }
    if (x<0) putchar('-'), x=-x;
    T num=0, ch[20];
    while (x) ch[++num]=x%10+48, x/=10;
    while (num) putchar(ch[num--]);
}

int ver[maxn<<1],edge[maxn<<1],Next[maxn<<1],cost[maxn<<1],head[maxn],len=1;
inline void add(int x,int y,int z,int c)
{
    ver[++len]=y,edge[len]=z,cost[len]=c,Next[len]=head[x],head[x]=len;
    ver[++len]=x,edge[len]=0,cost[len]=-c,Next[len]=head[y],head[y]=len;
}

int s,t;
int dist[maxn],incf[maxn],pre[maxn];
bool vis[maxn];
inline bool spfa()
{
    memset(dist,0xcf,sizeof(dist));
    memset(vis,0,sizeof(vis));
    queue<int>q;q.push(s);
    dist[s]=0,vis[s]=1,incf[s]=1<<30;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for (int i=head[x]; i; i=Next[i])
        {
            if (!edge[i]) continue;
            int y=ver[i];
            if (dist[y]<dist[x]+cost[i])
            {
                dist[y]=dist[x]+cost[i];
                incf[y]=min(incf[x],edge[i]);
                pre[y]=i;
                if (!vis[y]) q.push(y),vis[y]=1;
            }
        }
    }
    if (dist[t]==inf) return false;
    else return true;
}

long long maxflow,ans;
inline void update()
{
    int x=t;
    while (x!=s)
    {
        int i=pre[x];
        edge[i]-=incf[t];
        edge[i^1]+=incf[t];
        x=ver[i^1];
    }
    maxflow+=incf[t];
    ans+=dist[t]*incf[t];
}

int n,k;
inline int hash(int i,int j)
{
	return (i-1)*n+j;
}

int l[510],r[510],x[510],y[510],b[1010],tot=0,length[510];
int main()
{
	read(n);read(k);
	for (int i=1; i<=n; ++i)
	{
		read(l[i]);read(r[i]);read(x[i]);read(y[i]);
		b[++tot]=l[i],b[++tot]=x[i];
		length[i]=sqrt((ll)(l[i]-x[i])*(l[i]-x[i])+(ll)(r[i]-y[i])*(r[i]-y[i]));
	}
	sort(b+1,b+tot+1);
	int siz=unique(b+1,b+tot+1)-b-1;
	for (int i=1; i<=n; ++i)
	{
		l[i]=lower_bound(b+1,b+siz+1,l[i])-b;
		x[i]=lower_bound(b+1,b+siz+1,x[i])-b;
	}

	s=0,t=siz<<1|1;
	add(s,1,k,0),add(siz<<1,t,k,0);
	for (int i=1; i<(siz<<1); ++i) add(i,i+1,INF,0);
	for (int i=1; i<=n; ++i)
		if (l[i]!=x[i]) add(l[i]<<1|1,x[i]<<1,1,length[i]);
		else add(l[i]<<1,x[i]<<1|1,1,length[i]);

	while (spfa()) update();
	write(ans),puts("");
	return 0;
}
