#include <bits/stdc++.h>
using namespace std;
int n,m;
int root;
const int M =  8e5+10;
const int N = 4e5+10;
const int d = 16;
int h[N],e[M],ne[M];
int idx =0 ;
int depth[N];
int q[N];
int fa[N][d];

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

void bfs(){
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0; //跳过root的哨兵
    depth[root] = 1;
    int hh = 0,tt = 0;
    q[0] = root;
    while(hh<=tt){
        int t = q[hh++];
        for(int i =h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for(int k = 1;k<=15;k++)
                    fa[j][k] = fa[fa[j][k-1]][k-1];
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    for(int k = 15;k>=0;k--){
        if(depth[fa[a][k]]>=depth[b])
            a = fa[a][k];
    }
    if(a==b) return a;
    for(int k = 15;k>=0;k--){
        if(fa[a][k]!=fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}



int main(){
    memset(h,-1,sizeof h);
    cin>>n;
    for(int i =1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(b==-1) root = a;
        else {add(a,b);add(b,a);}
    }
    bfs();

    cin>>m;
    for(int i =1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        int p = lca(a,b);
        if(p==a) puts("1");
        else if(p==b) puts("2");
        else puts("0");
    }


    return 0;
}