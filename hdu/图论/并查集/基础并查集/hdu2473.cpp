//并查集的删除
//设置虚拟节点
#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int f[N];
bool v[N];
void init(int& n,int& m){
    for(int i =0;i<n;i++){
        f[i] = i+ n;
    }
    for(int i =n;i<=(n<<1) + m;i++)
        f[i] = i;
}

int find(int x){
    if(f[x]==x) return x;
    return f[x] = find(f[x]);
}

void merge(int x,int y){
    int fx = find(x);
    int fy = find(y);
    f[fy] = fx;
}

int main()
{
    int n,m,x,y,i,j,p=1;
    char a[2];
    while(scanf("%d%d",&n,&m),(n+m))
    {
        init(n,m);
        int cnt = 2*n;
        while(m--){
            scanf("%s",a);
            if(a[0] == 'M'){
                scanf("%d%d",&x,&y);
                merge(x,y);
            }
            if(a[0] == 'S'){
                scanf("%d",&x);
                f[x] = cnt++;
            }
        }
        memset(v, false, sizeof(v));
        int ans = 0;
        for(i = 0; i < n; i ++){
            if(!v[find(i)]){
                v[find(i)] = true;
                ans ++;
            }
        }
        printf("Case #%d: %d\n",p++,ans);
    }
    return 0;
}