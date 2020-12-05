#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL long long
#define pi acos(-1.0)
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
int head[110000], vis[1100000], path[1100000], cnt, a[10], top, stk[1100000], ww[1100000];
struct node {
        int u, v, w, next;
} edge[1100000];
void add(int u, int v, int w)
{
        edge[cnt].v=v;
        edge[cnt].w=w;
        edge[cnt].next=head[u];
        head[u]=cnt++;
}
void dfs(int u)
{
        int i, tt=0,w;
        stk[++tt]=u;
        ww[tt]=0;
        while(tt){
                u=stk[tt];
                for(i=head[u];i!=-1;i=edge[i].next){
                        if(!vis[edge[i].w]){
                                vis[edge[i].w]=1;
                                stk[++tt]=edge[i].v;
                                ww[tt]=edge[i].w;
                                head[u]=edge[i].next;
                                break;
                        }
                }
                if(i==-1){
                        path[top++]=ww[tt];
                        tt--;
                }
        }
}
void init()
{
        memset(head,-1,sizeof(head));
        cnt=top=0;
        memset(vis,0,sizeof(vis));
}
int main()
{
        int n, i, j, tot, tmp;
        a[0]=1;
        for(i=1; i<=6; i++) a[i]=a[i-1]*10;
        while(scanf("%d",&n)!=EOF&&n) {
                if(n==1) {
                        puts("0123456789");
                        continue ;
                }
                init();
                tot=a[n-1];
                for(i=0;i<tot;i++){
                        tmp=i%a[n-2]*10;
                        for(j=9;j>=0;j--){
                                add(i,tmp+j,i*10+j);
                        }
                }
                vis[0]=1;
                dfs(0);
                for(i=1;i<n;i++) printf("0");
                for(i=top-1;i>=0;i--){
                        printf("%d",path[i]%10);
                }
                puts("");
        }
        return 0;
}