//并查集维护最大路径最小值的种类数目,模版题
#include <bits/stdc++.h>
using namespace std;
int n,m,q;
const int MAXN = 10005;
const int inf = 0x3f3f3f3f;
int father[MAXN],num[MAXN];
long long out[MAXN];

struct Node{
    int u,v,w;
    bool operator<(const Node& a) const{
        return w<a.w;
    }
}edge[MAXN*10];

struct query{
    int l,id;
    bool operator<(const query& a) const{
        return l<a.l;
    }
}p[MAXN];

void init(){
    for(int i=1;i<=n;i++){
        father[i] = i;
        num[i] = 1;
    }
}

int find(int x){
    if(father[x]==x) return x;
    return father[x] = find(father[x]);
}

int merge(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx==fy) return 0;
    int t = num[fx] * num[fy];
    num[fx] += num[fy];
    num[fy] = 0;
    father[fy] = fx;
    return t;
}


int main(){
    while(~scanf("%d%d%d",&n,&m,&q)){
        init();
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        sort(edge+1,edge+m+1);
        for(int i =1;i<=q;i++){
            scanf("%d",&p[i].l);
            p[i].id = i;
        }
        sort(p+1,p+q+1);
        int pos = 1;
        long long ans = 0;
        for(int i=1;i<=q;i++){
            while(pos<=m && edge[pos].w <= p[i].l){
                ans+=merge(edge[pos].u,edge[pos].v);
                pos++;
            }
            out[p[i].id] = ans;
        }
        for(int i =1;i<=q;i++){
            printf("%lld\n",out[i]);
        }
    }
    return 0;
}