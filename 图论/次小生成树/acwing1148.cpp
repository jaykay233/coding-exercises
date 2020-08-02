#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Edge{
    int a,b,w;
    bool f;
    bool operator<(const  Edge e) const {
        return w<e.w;
    }
};
vector<Edge> v;
const int INF = 0x3f3f3f3f;
int idx =0 ;
const int N = 510;
const int M = N*N;
int e[M],h[N],w[M],ne[M];
int p[N];
int dist[N][N];

void add(int u,int v,int c){
    e[idx] = v;
    w[idx] = c;
    ne[idx] =h[u];
    h[u] = idx++;
}

int  find(int a){
    if(p[a]==a) return a;
    return p[a] = find(p[a]);
}

void dfs(int u,int fa,int maxd,int d[]){
    d[u] = maxd;
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        dfs(j,u,max(maxd,w[i]),d);
    }
    return;
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v.push_back({x,y,z});
    }
    for(int i =1;i<=N;i++) p[i] =i;

    sort(v.begin(),v.end());
    int sum = 0;
    for(int i=0;i<m;i++){
        auto &e = v[i];
        int fa = find(e.a);
        int fb = find(e.b);
        if(fa!=fb){
            p[fa] = fb;
            sum+=e.w;
            add(e.a,e.b,e.w);
            add(e.b,e.a,e.w);
            e.f = true;
        }
    }

    for(int i=1;i<=n;i++) dfs(i,-1,0,dist[i]);
    int res = INF;
    for(int i=0;i<m;i++){
        if(!v[i].f){
            int a = v[i].a;
            int b = v[i].b;
            int w = v[i].w;
            if(w>dist[a][b]){
                res =min(res,sum+w-dist[a][b]);
            }
        }
    }

    cout<<res<<endl;

    return 0;
}