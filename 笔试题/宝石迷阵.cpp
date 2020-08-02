#include <bits/stdc++.h>
using namespace std;
int n,q;
const int N = 20010;
const int M = N*2; 
int a[N];
int idx;
int e[M],h[N],ne[N],w[N];
typedef unsigned long long ULL;
const int P = 131;
int ans[N];
void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

unordered_map<ULL,int> dfs(int u,int father){
    unordered_map<ULL,int> heap;
    heap[0] = a[u];
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j!=father){
            auto S = dfs(j,u);
            for(auto item:S) heap[item.first * P + w[i]] += item.second;
        }
    }

    for(auto item:heap) ans[u] = max(ans[u],item.second);
    return heap;
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++){
        int a,b;
        char c[2];
        scanf("%d %d %s",&a,&b,c);
        add(a,b,*c);add(b,a,*c);
    }
    dfs(1,-1);
    for(int i=1;i<=q;i++){
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }

    return 0;
}