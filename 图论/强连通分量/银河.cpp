#include <bits/stdc++.h>
using namespace std;
const int N = 100010,M = 600010;
int dfn[N],low[N],timestamp;
int h[N],hs[N],e[M],ne[M],w[M];
int idx;
int stk[N],top;
bool in_stk[N];
int scc_cnt;
int id[N];
int sz[N];
int n,m;
int dist[N];
void add(int h[],int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;in_stk[u] = true;
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u] = min(low[u],dfn[j]);
        }
    }
    if(low[u] == dfn[u]){
        ++scc_cnt;
        int y;
        do{
            y = stk[top--];
            id[y] = scc_cnt;
            sz[scc_cnt]++;
            in_stk[y] = false;
        }while(y!=u);
    }

}


int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);
    for(int i =1;i<=n;i++) add(h,0,i,1);
    for(int i =0;i<m;i++){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(t==1) add(h,a,b,0),add(h,b,a,0);
        else if(t==2) add(h,a,b,1);
        else if(t==3) add(h,b,a,0);
        else if(t==4) add(h,b,a,1);
        else add(h,a,b,0);
    }   

    tarjan(0);
    bool success = true;
    for(int i =0;i<=n;i++){
        for(int j =h[i];j!=-1;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a==b){
                if(w[j]>0){
                    success = false;
                    break;
                }
            }else add(hs,a,b,w[j]);
        }
        if(!success) break;
    }

    if(!success) puts("-1");
    else{
        for(int i = scc_cnt;i;i--){
            for(int j =hs[i];j!=-1;j=ne[j]){
                int k =e[j];
                dist[k] = max(dist[k],dist[i]+w[j]);
            }
        }
        long long res = 0;
        for(int i =1;i<=scc_cnt;i++) res+=(long long)dist[i]*sz[i];
        printf("%lld\n",res);
    }

    return 0;
}