#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100007;
int ad[N*30],n,m,ch[N*30][2],root[N],tot,sz;
ll sum[N*30];

void update(int rt){
    sum[rt] = sum[ch[rt][0]] + sum[ch[rt][1]];
}

int build(int rt,int l,int r){
    rt = ++tot;
    if(l==r) {scanf("%lld",&sum[rt]);return rt;}
    int mid = (l+r)>>1;
    ch[rt][0] = build(ch[rt][0],l,mid);
    ch[rt][1] = build(ch[rt][1],mid+1,r);
    update(rt);
    return rt;
}

int add(int rt,int l,int r,int L,int R,int x){
    int rrt = ++tot;
    ch[rrt][0] = ch[rt][0];ch[rrt][1] = ch[rt][1];
    ad[rrt] = ad[rt];
    sum[rrt] = sum[rt];
    sum[rrt] += (ll)x*(min(R,r)-max(l,L)+1);
    if(L<=l && r<=R){
        ad[rrt]+=x;
        return rrt;
    }
    int mid = (l+r)>>1;
    if(L<=mid) ch[rrt][0] = add(ch[rrt][0],l,mid,L,R,x);
    if(R>mid) ch[rrt][1] = add(ch[rrt][1],mid+1,r,L,R,x);
    return rrt;
}

ll query(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return sum[rt];
    }
    ll ret = (ll)ad[rt]*(min(R,r)-max(l,L)+1), mid = (l+r)>>1;
    if(L<=mid) ret+=query(ch[rt][0],l,mid,L,R);
    if(R>mid) ret+=query(ch[rt][1],mid+1,r,L,R);
    return ret;
}

void init(){
    tot =0,sz=0;
    memset(sum,0,sizeof sum);
    memset(ad,0,sizeof ad);
    memset(root,0,sizeof root);
}


int main(){
    while(~scanf("%d%d",&n,&m)){
    init();
    root[0]=build(0,1,n);
    for(;m--;){
        int x,y,z;
        char c;
        scanf(" %c",&c);
        if(c=='C'){
            scanf("%d%d%d",&x,&y,&z);
            root[sz+1]=add(root[sz],1,n,x,y,z);
            sz++;
        }
        else
        if(c=='Q'){
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(root[sz],1,n,x,y));
        }
        else
        if(c=='H'){
            scanf("%d%d%d",&x,&y,&z);
            printf("%lld\n",query(root[z],1,n,x,y));
        }
        else
        if(c=='B'){
            scanf("%d",&sz);
        }
    }
}
    return 0;
}


