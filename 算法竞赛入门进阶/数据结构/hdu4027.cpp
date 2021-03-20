#include <bits/stdc++.h>
using namespace std;
int N;
const int MAXN = 100010;
int a[MAXN];
int M;
int T;
int X,Y;

struct node{
    int l,r;
    int sum;
    int minus;
}nodes[MAXN<<2];



void pushup(int o){
    nodes[o].sum = nodes[o<<1].sum + nodes[o<<1|1].sum;
}

void pushdown(int o){
    if(nodes[o].minus!=0){
        nodes[o<<1].minus = nodes[o].minus;
        nodes[o<<1|1].minus = nodes[o].minus;
        nodes[o].minus = 0;
    }
}
void build(int o,int l,int r){
    if(l==r){
        nodes[o].l = l;
        nodes[o].r = r;
        nodes[o].sum = a[l];
        nodes[o].minus =0 ;
        return;
    }
    int mid = l + r>> 1;
    build(o<<1,l,mid);
    build(o<<1|1,mid+1,r);
    pushup(o);
}

void update(int o,int ql,int qr){
    if(ql<=nodes[o].l && nodes[o].r <=qr){
        nodes[o].sum -= nodes[o].minus * (qr-ql+1);
        nodes[o].minus += 1;
        return;
    }
    pushdown(o);
    int mid = (nodes[o].l + nodes[o].r) >> 1;
    if(qr<=mid) update(o<<1,ql,qr);
    else if(ql>mid) update(o<<1|1,ql,qr);
    else{
        update(o<<1,ql,qr);
        update(o<<1|1,ql,qr);
    }
    pushup(o);
}

int query(int o,int ql,int qr){
    if(ql<=nodes[o].l && nodes[o].r<=qr){
        return nodes[o].sum;
    }
    pushdown(o);
    int mid = (nodes[o].l + nodes[o].r)>>1;
    int ans = 0;
    if(ql<=mid) ans+=query(o<<1,ql,qr);
    if(qr>mid) ans += query(o<<1|1,ql,qr);
    return ans;
}

int main(){
    int cnt = 1;
    while(~scanf("%d",&N) ){
        for(int i=1;i<=N;i++){
            scanf("%d",&a[i]);
        }
        build(1,1,N);
        scanf("%d",&M);
        printf("Case #d:\n",cnt);
        for(int i=1;i<=M;i++){
            scanf("%d%d%d",&T,&X,&Y);
            if(T==0){
                update(1,X,Y);
            }
            else if(T==1){
                printf("%d\n",query(1,X,Y));
            }
        }
        cnt++;
    }
    
    return 0;
}