#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 110;
int res[N][N];
int a[N][N];
bool st[N][N];
int main(){
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int d =0,x = 0, y =0;
    for(int i =1;i<=n*m;i++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx<0 || nx>=n || ny<0 || ny>=m || st[nx][ny]){
            d = (d+1)%4;
            nx = x + dx[d], ny = y + dy[d];
        }
        res[x][y] = i;
        st[x][y] = true;

        x = nx,y=ny;
    }

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++) cout<<res[i][j]<<' ';
        cout<<endl;
    }


    return 0;
}