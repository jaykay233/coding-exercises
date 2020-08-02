#include <bits/stdc++.h>
using namespace std;
int n,p,m;
const int N = 100010;
int w[N];

struct Node
{
    int l, r;
    int sum, add, mul;
}tr[N * 4];


typedef long long LL;

void pushup(int u){
    tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum)%p;
}

void eval(Node &t, int add, int mul)
{
    t.sum = ((LL)t.sum * mul + (LL)(t.r - t.l + 1) * add) % p;
    t.mul = (LL)t.mul * mul % p;
    t.add = ((LL)t.add * mul + add) % p;
}

void pushdown(int u)
{
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,w[r],1,0};
    else{
        tr[u] = {l,r,0,0,1};
        int mid = (l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int add,int mul){
    if(l<= tr[u].l && tr[u].r<=r){
        eval(tr[u],add,mul);
    }else{
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(l<=mid) modify(u<<1,l,r,add,mul);
        if(r>mid) modify(u<<1|1,l,r,add,mul);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(l<=tr[u].l && tr[u].r <=r){
        return tr[u].sum;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    int sum = 0;
    if(l<=mid) { sum += query(u<<1,l,r); sum%=p;}
    if(r>mid) {sum += query(u<<1|1,l,r); sum%=p;}
    return sum;
}

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    build(1, 1, n);

    scanf("%d", &m);
    while (m -- )
    {
        int t, l, r, d;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            scanf("%d", &d);
            modify(1, l, r, 0, d);
        }
        else if (t == 2)
        {
            scanf("%d", &d);
            modify(1, l, r, d, 1);
        }
        else printf("%d\n", query(1, l, r));
    }

    return 0;
}