#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int n,m;
bool st[N][N];
int mp[N][N];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int matchx[N][N];
int matchy[N][N];


bool find(int x,int y){
    for(int i =0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=1 && nx<=n && ny>=1 && ny<=n && !st[nx][ny] && !mp[nx][ny]){
            st[nx][ny] = true;
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
    long long res = 0;
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            memset(st,false,sizeof st);
            if(mp[i][j]) continue;
            if(find(i,j)) res++;
        }
    }

    res/=2;
    cout<<res<<endl;

    return 0;
}