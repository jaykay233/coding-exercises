#include <bits/stdc++.h>
using namespace std;
int t;
int n,q;
char a[2];
int x,y;
const int N = 10010;
int fa[N];
int dist[N];
int num[N];

void init(){
    for(int i =0;i<N;i++){
        fa[i] = i;
        num[i] = 1;
        dist[i] = 0;
    }
}


int find(int x)//返回x所属的连通分量且更新d[x]为x到根的距离
{
    if(fa[x]==x)return x;
    int root= find(fa[x]);
    dist[x] += dist[fa[x]];//注意这里
    return fa[x] = root;
}

void merge(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx==fy) return;
    fa[fx] = fy;    
    dist[fx]=1;
    num[fy] += num[fx];
}

// void merge(int x,int y){
//     int fx=find(x);
//     int fy=find(y);
//     if(fx!=fy)
//     {
//         fa[fx]=fy;
//         num[fy]+=num[fx];
//         dist[fx]=1;//注意这里
//     }
// }



int main(){
    scanf("%d",&t);
    for(int j =1;j<=t;j++){
        init();
        scanf("%d%d",&n,&q);
        printf("Case %d:\n",j);
        for(int i =1;i<=q;i++){
            scanf("%s",a);
            if(a[0]=='T'){
                scanf("%d%d",&x,&y);
                merge(x,y);
            }else if(a[0]=='Q'){
                scanf("%d",&x);
                int fx = find(x);
                printf("%d %d %d\n",fx,num[fx],dist[x]);
            }
        }
    }

    return 0;
}