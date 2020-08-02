#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e4+10;
const int M = 2e5+10;
int h[N],e[2*N],w[2*N],ne[2*N];
int idx=0;
typedef pair<int,int> PII;
vector<PII> query[N];
int res[M];
int st[N];
int p[N];
int dist[N];

void add(int a,int b,int k){
    e[idx] = b;w[idx] = k;ne[idx] = h[a];h[a] = idx++;
}

int find(int x){
    if(p[x]!=x) return p[x] = find(p[x]);
    return p[x];
}

void dfs(int u,int fa){
    for(int i =  h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        dist[j] = dist[u] + w[i];
        dfs(j,u);
    }
    return;
}


void tarjan(int u){
    st[u] = 1;
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            tarjan(j);
            p[j] = u;
        }
    }
    for(auto item:query[u]){
        int ver = item.first, idx = item.second;
        if(st[ver]==2){
            int y = find(ver);
            res[idx] = dist[u] + dist[ver] - 2*dist[y];
        }
    }
    st[u] = 2;
}


int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i =1;i<=n-1;i++){
        int x,y,k;
        cin>>x>>y>>k;
        add(x,y,k);add(y,x,k);
    }
    for(int i =1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        if(x!=y){
            query[x].push_back({y,i});
            query[y].push_back({x,i});
        }
    }

    for(int i =1;i<=n;i++) p[i] = i;
    dfs(1,-1);
    tarjan(1);
    for(int i =1;i<=m;i++) cout<<res[i]<<endl;

    return 0;
}