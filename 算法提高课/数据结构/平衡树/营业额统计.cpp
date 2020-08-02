#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 33010, INF = 1e7;

int n;
struct Node{
    int l,r;
    int key,val;
}tr[N];

int root, idx;

int getNode(int key){
    tr[++idx].key = key;
    tr[idx].val = rand();
    return idx;
}

void build(){
    getNode(-INF);getNode(INF);
    root = 1,tr[1].r = 2;
}
//       
//     x(p)                x (q)
//   x(q)   x            x   x (p)
// x  x                    x   x

void zig(int& p){
    int q = tr[p].l;
    tr[p].l = tr[q].r , tr[q].r = p, p = q;
}

void zag(int& p){
    int q = tr[p].r;
    tr[p].r = tr[q].l , tr[q].l = p, p = q; 
}


void insert(int& p,int key){
    if(!p) p =getNode(key);
    else if(tr[p].key == key) return;
    else if(tr[p].key > key){
        insert(tr[p].l,key);
        if(tr[tr[p].l].val > tr[p].val) zig(p);
    }else {
        insert(tr[p].r,key);
        if(tr[tr[p].r].val > tr[p].val) zag(p);
    }
}

int get_prev(int p,int key){
    if(!p) return -INF;
    if(tr[p].key > key) return get_prev(tr[p].l,key);
    return max(tr[p].key, get_prev(tr[p].r,key));
}

int get_next(int p,int key){
    if(!p) return INF;
    if(tr[p].key<key) return get_next(tr[p].r,key);
    return min(tr[p].key,get_next(tr[p].l,key));
}


int main(){
    build();
    scanf("%d",&n);
    long long res =0 ;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(i==1) res+=x;
        else res += min(x-get_prev(root,x), get_next(root,x) - x);
        insert(root,x);
    }
    printf("%lld\n",res);
    

    return 0;
}