#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 210;
vector<pair<int,int>> edges;
int f1[N];
int f2[N];
int ans;
bool g[N][N];

void dfs(int u,int father){
    for(int i =1;i<=n;i++){
        if(g[u][i] && i!=father ){
            dfs(i,u);
            if(f1[u]<f1[i] + 1){
                f2[u] = f1[u];
                f1[u] = f1[i] + 1;
            }else if(f2[u] < f1[i]+1){
                f2[u] = f1[i] + 1;
            }
        }
        ans = max(ans,f1[u] + f2[u]);
    }
}

int main(){
    scanf("%d",&n);
    
    for(int i =1;i<=n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        edges.push_back({x,y});
        g[x][y] = g[y][x] = true;
    }


    int res = 0;
    for(int u =1;u<=n;u++){
        for(int v = 1;v<=n;v++){
            if(g[u][v]){
                memset(f1,0,sizeof f1);
                memset(f2,0,sizeof f2);
                ans = 0;
                dfs(u,v);
                int ans1 = ans;
                ans =0;
                dfs(v,u);
                int ans2 = ans;
                res = max(res,ans1 * ans2);
            }
        }
    }
    cout<<res<<endl;

    return 0;
}