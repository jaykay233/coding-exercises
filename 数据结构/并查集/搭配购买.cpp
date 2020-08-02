#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int W = 10010;
int p[N],c[N],d[N];
int n,m,w;
int dp[W];

int find(int a){
    if(p[a]!=a) {
        p[a] = find(p[a]);
    }
    return p[a];
}


int main(){
    cin>>n>>m>>w;
    for(int i = 1;i<=N;i++) p[i] = i;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>d[i];
    }
    for(int i =1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int fx = find(x);
        int fy = find(y);
        if(fx!=fy){
            p[fx] = fy;
            d[fy] += d[fx];
            c[fy] += c[fx];
        }
    }


    for(int i =1;i<=n;i++){
        if(p[i]!=i) continue;
        for(int j = w;j>=c[i];j--){
            dp[j] = max(dp[j],dp[j-c[i]] + d[i]);
        }
    }

    printf("%d\n",dp[w]);

    return 0;
}
