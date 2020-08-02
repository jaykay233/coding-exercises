#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e5+10;
const int M = 2e5+10;
int h[N],e[M],ne[M];
int idx=0;
int d[N];
int q[N];
int ans;
int depth[N],fa[N][17];

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

void bfs(){
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0;
    depth[1] = 1;
    int hh =0,tt =0 ;
    q[0] = 1;
    while(hh<=tt){
        int t = q[hh++];
        for(int i =h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(depth[j] > depth[t]+1){
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for(int k=1;k<=16;k++){
                    fa[j][k] = fa[fa[j][k-1]][k-1];
                }
            }
        }
    }
    return;
}


int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    for(int k= 16;k>=0;k--){
        if(depth[fa[a][k]]>=depth[b]) a = fa[a][k];
    }
    if(a==b) return a;
    for(int k = 16;k>=0;k--){
        if(fa[a][k]!=fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int dfs(int u,int fa){
    int res = d[u];
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        int s = dfs(j,u);
        if(s==0) ans+=m;
        else if(s==1) ans+=1;
        res+=s;
    }
    return res;
}


int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    bfs();
    for(int i =1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int p = lca(x,y);
        d[x] ++,d[y]++,d[p]-=2;
    }
    dfs(1,-1);
    cout<<ans<<endl;

    return 0;
}