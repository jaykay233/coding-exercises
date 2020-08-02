//最大独立集 = n - 最小点数覆盖
//推导过程：
//最少去掉多少点，使得点和点之间没有边
//最少点等价于最小点数覆盖
//等于找最大独立集
//棋盘问题可以用二分图或者状态压缩dp
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 110;
bool g[N][N];
bool st[N][N];
typedef pair<int,int> PII;
PII match[N][N];
int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};

bool find(int x,int y){
    for(int i =0;i<8;i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if(a<1 || a>n || b<1 || b>m) continue;
        if(g[a][b] || st[a][b]) continue;
        st[a][b] = true;
        if(match[a][b].first==0 || find(match[a][b].first,match[a][b].second)){
            match[a][b] = {x,y};
            return true;
        }
     }
     return false;
}

int main(){
    cin>>n>>m>>k;
    for(int i =0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y] = true;
    }

    long long res = 0;
    for(int i =1 ;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)%2 || g[i][j]) continue;
            memset(st,0,sizeof st);
            if(find(i,j)) res++;
        }
    }

    cout<<n*m-k-res << endl;

    return 0;
}