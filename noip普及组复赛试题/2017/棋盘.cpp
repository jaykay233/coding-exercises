#include <bits/stdc++.h>
using namespace std;
int m,n;
const int M = 110;
int dis[M][M];
int color[M][M];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
const int INF = 0x3f3f3f3f;

bool check(int x,int y){
    if(x>=1 && x<=m && y>=1 && y<=m) return true;
    return false;
}

void dfs(int x,int y,int m,int f){
    if(m>=dis[x][y]) return;
    dis[x][y] = m;
    for(int i=0;i<4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(!check(tx,ty)) continue;
        if(!color[tx][ty]){
            if(f){
                color[tx][ty] = color[x][y];
                dfs(tx,ty,m+2,0);
                color[tx][ty] = 0;
            }
        }
        else if(color[tx][ty]==color[x][y]) dfs(tx,ty,m,1);
        else dfs(tx,ty,m+1,1);
    }
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        color[x][y] = c+1;
    }
    memset(dis,0x3f,sizeof dis);
    dfs(1,1,0,1);
    if(dis[m][m] == INF ) printf("-1");
    else printf("%d",dis[m][m]);
    return 0;
}