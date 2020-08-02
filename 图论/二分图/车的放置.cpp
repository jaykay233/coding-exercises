#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int ban[N][N];
int vis[N];
int n,m,t,match[N];

bool dfs(int x){
    for(int y =1;y<=m;y++){
        if(!vis[y] && !ban[x][y]){
            vis[y] = true;
            if(!match[y] || dfs(match[y])){
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=t;i++){
        int x,y;
        cin>>x>>y;
        ban[x][y] = true;
    }
    int ans =0 ;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) ans++;
    }
    cout<<ans<<endl;

    return 0;
}