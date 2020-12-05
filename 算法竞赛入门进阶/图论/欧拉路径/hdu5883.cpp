//如果欧拉回路作为起始点还要多访问一次

// 1.根据欧拉路径/欧拉回路的性质判定是否存在
// 2.分析每个点的贡献
// 3.每个点被访问 (度/2) 次
// 4.因此只有被访问奇数次的点产生贡献
// 5.作为初始点 访问次数+1
// 6.考虑初始点
// 7.如果是欧拉回路，每个点都可能是初始点
// 8.如果是欧拉路径，只有起点和终点可能是初始点
// 9.枚举初始点，ans取max即可


#include<bits/stdc++.h>
using namespace std;
const int M=100005;
int n,m,A[M];
int du[M];
int par[M];
int get_fa(int x) {
    if(par[x]==x)return x;
    return par[x]=get_fa(par[x]);
}
void rd(int &res) {
    res=0;
    char c;
    while(c=getchar(),c<48);
    do {
        res=(res<<3)+(res<<1)+(c&15);
    } while(c=getchar(),c>47);
}
int main() {
    int cas;
    int a,b;
    rd(cas);
    while(cas--) {
        rd(n),rd(m);
        for(int i=1; i<=n; i++) {
            rd(A[i]);
            du[i]=0;
            par[i]=i;
        }
        for(int i=1; i<=m; i++) {
            rd(a),rd(b);
            du[a]++,du[b]++;
            int x=get_fa(a),y=get_fa(b);
            if(x==y)continue;
            par[x]=y;
        }
        int cnt=0,blk=0;
        int ans=0;
        for(int i=1; i<=n; i++) {
            if(par[i]==i)blk++;
            if(du[i]&1)cnt++;
            if((du[i]/2)&1)ans^=A[i];
        }
        //每个点被访问 度/2 次 (奇度点+1)
        //被访问奇数次产生贡献
        //作为初始点 访问次数+1
        if(blk>1||cnt!=0&&cnt!=2) {
            printf("Impossible\n");
        } else if(cnt==2) {
            for(int i=1;i<=n;i++){
                if(du[i]&1)ans^=A[i];
            }
            printf("%d\n",ans);
        } else {
            int mx=0;
            for(int i=1; i<=n; i++) {
                mx=max(mx,ans^A[i]);
            }
            printf("%d\n",mx);
        }
    }
    return 0;
}