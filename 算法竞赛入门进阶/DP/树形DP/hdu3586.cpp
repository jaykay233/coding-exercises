#include <bits/stdc++.h>
using namespace std;

#define siz 1005
const int inf = 0x3f3f3f;
int n,m,head[siz],Enum=0,dp[siz];
struct node{
    int w,to,ne;
}edge[siz<<1];

void init(){
    memset(head,-1,sizeof head);
    Enum =0;
}

void add_edge(int a,int b,int c){
    edge[Enum].to = b;
    edge[Enum].w = c;
    edge[Enum].ne = head[a];
    head[a] = Enum++;
}

void dfs(int u,int fa,int lim){
    dp[u] = 0;
    int v,flag=0;
    for(int i=head[u];i!=-1;i=edge[i].ne){
        v = edge[i].to;
        if(v==fa) continue;
        flag = 1;
        dfs(v,u,lim);
        if(edge[i].w<=lim) dp[u] += min(edge[i].w,dp[v]);
        else dp[u] += min(inf,dp[v]);
    }
    if(flag==0) dp[u] = inf;
}

bool check(int lim){
    for(int i=1;i<=n;i++) dp[i] = inf;
    dfs(1,-1,lim);
    return dp[1]<=m;
}

int main(){
    while(scanf("%d%d",&n,&m) && (n||m)){
        init();
        int a,b,c;
        for(int i=1;i<=n-1;i++){
            scanf("%d %d %d",&a,&b,&c);
            add_edge(a,b,c);add_edge(b,a,c);
        }
        int low=1,high=m,mid,ans=-1;
        while(low<high){
            mid = (low + high) >> 1;
            if(check(mid)) {
                high = mid; 
            }else low = mid + 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}