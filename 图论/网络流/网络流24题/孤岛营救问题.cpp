#include <cstdio>
#include <algorithm>
#include <queue>

const int N=12;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m,e[N][N][N][N],cnt[N][N],key[N][N][N];
bool vis[N][N][1<<14];
struct node {
    int x,y,k,d;
    node() {x=y=k=d=0;}
    node(int _x,int _y,int _k,int _d) {
        x=_x,y=_y,k=_k,d=_d;
    }
};

int getkey(int x,int y) {
    int ans=0;
    for(int i=1;i<=cnt[x][y];++i) ans|=(1<<(key[x][y][i]-1));
    return ans;
}
int bfs(int sx,int sy) {
    std::queue<node> q;
    int sk=getkey(sx,sy);
    q.push(node(sx,sy,sk,0)),vis[sx][sy][sk]=1;
    while(!q.empty()) {
        node u=q.front(); q.pop();
        if(u.x==n&&u.y==m) return u.d;
        int ux=u.x,uy=u.y;
        for(int i=0;i<4;++i) {
            int vx=ux+dx[i],vy=uy+dy[i],opt=e[ux][uy][vx][vy];
            if(vx<1||vx>n||vy<1||vy>m||opt<0||(opt&&!(u.k&(1<<(opt-1))))) continue;
            int nxt=u.k|getkey(vx,vy);
            if(vis[vx][vy][nxt]) continue;
            q.push(node(vx,vy,nxt,u.d+1)),vis[vx][vy][nxt]=1;
        }
    }
    return -1;
}
int main() {
    int k,s;
    scanf("%d%d%*d",&n,&m);
    for(scanf("%d",&k);k--;) {
        int x1,y1,x2,y2,g;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
        if(g) e[x1][y1][x2][y2]=e[x2][y2][x1][y1]=g;
        else e[x1][y1][x2][y2]=e[x2][y2][x1][y1]=-1;
    }
    for(scanf("%d",&s);s--;) {
        int x,y,q;
        scanf("%d%d%d",&x,&y,&q);
        key[x][y][++cnt[x][y]]=q;
    }
    printf("%d\n",bfs(1,1));
    return 0;
}