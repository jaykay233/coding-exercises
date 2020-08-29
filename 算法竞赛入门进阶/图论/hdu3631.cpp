//https://blog.csdn.net/u010372095/article/details/45030825
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 1005;
const int inf = 999999999;

int mark[N],n,mapt[N][N];

void init(){
    for(int i =0;i<=n;i++){
        mark[i]=0;
        for(int j=0;j<=n;j++)
            mapt[i][j]=inf;
        mapt[i][i]=0;
    }
}

void floyd(int k){
    for(int i =0;i<n;i++)
        if(i!=k)
        for(int j =0;j<n;j++){
            if(i!=j && k!=j)
                if(mapt[i][j] > mapt[i][k] + mapt[k][j])
                    mapt[i][j] = mapt[i][k] + mapt[k][j];
        }
}

int main(){
    int cas=0,m,q,a,b,c,op,flag=0;
    while(scanf("%d%d%d",&n,&m,&q)>0){
        if(n+m+q==0)
            break;
        if(flag)
            printf("\n");
        flag = 1;
        init();
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            if(mapt[a][b] > c)
                mapt[a][b] = c;
        }
        printf("Case %d:\n",++cas);
        while(q--){
            scanf("%d%d",&op,&a);
            if(op==0){
                if(mark[a])
                    printf("ERROR! At point %d\n",a);
                else{
                    mark[a]=1;floyd(a);
                }
            }else{
                scanf("%d",&b);
                if(mark[a]==0 || mark[b]==0)
                    printf("ERROR! At path %d to %d\n",a,b);
                else if(mapt[a][b]<inf)
                    printf("%d\n",mapt[a][b]);
                else 
                    printf("No such path\n");
            }
        }
    }
    return 0;
}