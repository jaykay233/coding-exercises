#include <bits/stdc++.h>
using namespace std;
const int K = 11;
const int N = 55;
const int M = 1010;
int e[M],ne[M],h[N],w[M];
int f[N][1<<K];
int T;
int n,m,k;
int idx=0;
bool inq[N];
const int INF = 0x3f3f3f3f;
queue<int> q;
int g[1<<K];

void addEdge(int u,int v,int c){
    e[++idx] = v;w[idx]=c;ne[idx]=h[u];h[u]=idx;
    e[++idx] = u;w[idx]=c;ne[idx]=h[v];h[v]=idx;
}

bool check(int sta){
    int t =0 ;
    for(int i =0;i<k && sta;i++,sta>>=1){
        if(sta&1) t++; 
    }
    for(int i =k;i<2*k && sta;i++,sta>>=1){
        if(sta&1) t--;
    }
    return t==0;
}

void spfa(int S){
    while(!q.empty()){
        int x = q.front();q.pop();inq[x] = 0;
        for(int i =h[x];i;i=ne[i]){
            int j = e[i];
            if(f[j][S] > f[x][S] + w[i]){
                f[j][S] = f[x][S] + w[i];
                if(!inq[j]){
                    inq[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    return;
}

void dp(){
    memset(f,0x3f,sizeof f);
    for(int i = 1;i<=k;i++) f[i][1<<(i-1)] =0,f[n-i+1][1<<(i+k-1)] = 0;
    int cnt = k<<1;
    while(!q.empty()) q.pop();
    for(int S=1;S<(1<<cnt);S++){
        for(int s=S&(S-1);s;s=(s-1) & S)
            for(int i=1;i<=n;i++)
                f[i][S] = min(f[i][S],f[i][s] + f[i][s^S]);
        for(int i=1;i<=n;i++)
            if(f[i][S]<INF && !inq[i])
                q.push(i),inq[i]=1;
        spfa(S);
    }
    memset(g,0x3f,sizeof g);
    for(int i=1;i<(1<<cnt);i++)
        for(int j=1;j<=n;j++)
            g[i] = min(g[i],f[j][i]);
    
    for(int i=1;i<(1<<cnt);i++)
        if(check(i))
            for(int s=i&(i-1);s;s=(s-1) & i){
                if(check(s)){
                    g[i] = min(g[i],g[s] + g[i^s]);
                }
            }
    if(g[(1<<cnt)-1]>=INF/2) printf("No solution\n");
    else printf("%d\n",g[(1<<cnt)-1]);
    return;
}


int main(){
    scanf("%d",&T);
    for(int i =0;i<T;i++){
        scanf("%d%d%d",&n,&m,&k);
        memset(h,0,sizeof h);
        memset(inq,0,sizeof inq);
        idx =0;
        for(int i =0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        dp();
    }
    return 0;
}