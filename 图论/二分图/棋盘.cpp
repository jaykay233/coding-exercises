#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int n,m;
int mp[200][200];
bool vis[200][200];
int matchx[200][200];
int matchy[200][200];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool find(int x,int y){
    for(int i =0;i<4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx>=1 && nx<=n && ny>=1 && ny<=n && !vis[nx][ny] && !mp[nx][ny]){
            vis[nx][ny] = true;
            if(!matchx[nx][ny] || find(matchx[nx][ny],matchy[nx][ny])){
                matchx[nx][ny] = x;
                matchy[nx][ny] = y;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    for(int i =1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mp[u][v] = 1;
    }
    ll ans = 0;
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            memset(vis,false,sizeof vis);
            if(mp[i][j]) continue;
            if(find(i,j)) ans++;
        }
    }

    ans/=2;
    cout<<ans<<endl;

    return 0;
}