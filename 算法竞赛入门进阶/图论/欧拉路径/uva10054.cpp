#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 55;
int T;
int m;

int num[55];
int vis[55][55];
int u,v;

void dfs(int u){
    for(int i=1;i<maxn;i++){
        if(vis[u][i]){
            vis[u][i]--;
            vis[i][u]--;
            dfs(i);
            printf("%d %d\n",i,u);
        }
    }
}


int main(){
    scanf("%d",&T);
    for(int t =1;t<=T;t++){
        scanf("%d",&m);
        memset(num,0,sizeof num);
        memset(vis,0,sizeof vis);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            vis[u][v]++;
            vis[v][u]++;
            num[u]++;
            num[v]++;
        }  
        
        int ok = 1;
        for(int i=1;i<maxn;i++){
            if(num[i]%2){
                ok = 0;
                break;
            }
        }
        if(t!=1) printf("\n");
        printf("Case #%d\n",t);
        if(!ok)
            printf("some beads may be lost\n");
        else{
            for(int i=1;i<maxn;i++)
                dfs(i);
        }
    }
    return 0;
}