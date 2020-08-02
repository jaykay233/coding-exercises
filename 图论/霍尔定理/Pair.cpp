//hall定理是判断二分图完美匹配的证明
//定理描述，完美匹配存在的条件是：
// 点数 |X| = |Y|
// X的子集对应元素的数量小于等于这个子集对应匹配点的并集的元素的数量 |X|<=|M(X)|
#include <bits/stdc++.h>
using namespace std;
const int N = 2*1000*100;
int a[N],b[N];
int n,m,h;
int val[N<<2],la[N<<2];

int getid(int x){
    return lower_bound(b+1,b+1+m,x)-b;
}

void pushup(int rt){
    val[rt] = min(val[rt<<1],val[rt<<1|1]);
}



void pushdown(int rt){
    if(la[rt]){
        int k = la[rt];
        la[rt<<1] += k;
        la[rt<<1|1] += k;
        val[rt<<1] += k;
        val[rt<<1|1] += k;
        la[rt] = 0;
    }
}


void build(int rt,int l,int r){
    la[rt] =0;
    if(l==r){
        val[rt] = -l;return;
    }
    int mid = (l + r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void change(int rt,int l,int r,int ql,int qr,int k){
    if(ql>qr) return;
    if(ql<=l && r<=qr){
        val[rt]+=k;la[rt]+=k;
        return;
    }
    pushdown(rt);
    int mid = (l + r)>>1;
    if(ql<=mid) change(rt<<1,l,mid,ql,qr,k);
    if(qr>mid) change(rt<<1|1,mid+1,r,ql,qr,k);
    pushup(rt);
} 

int main(){
    int ans = 0;
    scanf("%d%d%d",&n,&m,&h);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i =1;i<=n;i++) scanf("%d",&a[i]);
    sort(b+1,b+m+1);
    build(1,1,m);
    for(int i=1;i<=m;i++){
        change(1,1,m,getid(h-a[i]),m,1);
    }
    if(val[1]>=0) ans++;
    for(int i =m+1;i<=n;i++){
        change(1,1,m,getid(h-a[i-m]),m,-1);
        change(1,1,m,getid(h-a[i]),m,1);
        if(val[1]>=0) ans++;
    } 
    printf("%d\n",ans);

    return 0;
}