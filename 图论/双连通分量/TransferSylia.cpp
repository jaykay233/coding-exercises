// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int cut =0 ;
const int N = 510;
const int M = N * N/2;
int h[N],e[M],ne[M];
int dfn[N],low[N],dfstime;
int root;
int del;
int idx;
int tot;

void add(int u,int v){
    e[idx] = v;ne[idx] = h[u];h[u] = idx++;
}

void tarjan(int u,int p){
    if(cut) return;
    dfn[u] = low[u] = ++dfstime;
    int cnt = 0;
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j ==p || j==del) continue;
        if(!dfn[j]){
            cnt++;
            tarjan(j,u);
            low[u] = min(low[u],low[j]);
            if( (u==root && cnt>1) || (u!=root && low[j]>=dfn[u])){
                cut = 1;
                return;
            }
        }
        else low[u] = min(low[u],dfn[j]);
    }
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) && n){
        memset(h,-1,sizeof h);
        idx =0 ;
        for(int i =0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        cut =0 ;
        for(int i =0;i<n;i++){
            del = i;
            memset(dfn,0,sizeof dfn);
            tot =0 ;
            root = !i;
            tarjan(root,-1);
            if(cut) break;
            for(int j =0;j<n;j++){
                if(j!=del && !dfn[j]){
                    cut = 1;
                    break;
                }
            }
            if(cut) break;
        }
        printf("%s\n",cut?"NO":"YES");
    }
    return 0;
}