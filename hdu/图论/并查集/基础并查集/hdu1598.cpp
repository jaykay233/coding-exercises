//枚举+最小生成树
#include <bits/stdc++.h>
using namespace std;
#define MAXN 210
#define INF 0x3f3f3f3f
int f[MAXN],rk[MAXN],n,m,pos;

struct Edge{
    int u,v,val;
    bool operator<(const Edge& a)const {
        return val<a.val;
    }
}arr[MAXN*MAXN];

void init(){
    for(int i =0;i<MAXN;i++)
        f[i] = i, rk[i]  =0;
}

int find(int a){
    if(f[a]==a) return a;
    return f[a] = find(f[a]);
}

void merge(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(rk[fa] > rk[fb])
        f[fb] = fa;
    else{
        if(rk[fa] == rk[fb])
            ++rk[fb];
        f[fa] = fb;
    }
}


int main(){
    int u,v,speed,Q;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i =1;i<=m;i++){
            scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].val);
        }    
        sort(arr+1,arr+m+1);
        scanf("%d",&Q);
        for(int i =1;i<=Q;i++){
            scanf("%d%d",&u,&v);
            int ans = INF;
            for(int j =1;j<=m;j++){
                init();
                for(int k =j;k<=m;k++){
                    merge(arr[k].u,arr[k].v);
                    if(find(u) == find(v)){
                        ans = min(ans,arr[k].val - arr[j].val);
                        break;
                    }
                }
            }
            if(ans == INF) printf("-1\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}