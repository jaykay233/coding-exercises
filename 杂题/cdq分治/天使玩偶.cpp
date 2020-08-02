#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 1e7+10;
const int INF = 2e7+10;
int n,q,opt,x,y,len;

struct node {
    int x,y,type,id,ans;
} a[maxn],b[maxn],tem[maxn];

struct BIT {
    int m[maxn];
    int lowbit(int x) {
        return x & -x;
    }
    void update(int x,int v) {
        for(; x <= len; x+= lowbit(x))
            m[x] = max(m[x],v);
    }
    int query(int x) {
        int ans = 0;
        for(; x; x-=lowbit(x))
            ans = max(ans,m[x]);
        return ans?ans:-INF;
    }
    void clear(int x) {
        for(; m[x]; x+= lowbit(x))
            m[x] = 0;
    }
} tree;

void cdq(int L,int R) {
    if(L == R) return;
    int mid = (L+R) >> 1;
    cdq(L,mid),cdq(mid+1,R);
    int t1 = L,t2 = mid+1;
    int k = L;
    while(t2 <= R) {
        while(t1 <= mid && b[t1].x <= b[t2].x) {
            if(b[t1].type == 1)
                tree.update(b[t1].y, b[t1].x+b[t1].y);
            tem[k++] = b[t1++];
        }
        if(b[t2].type == 2)
            a[b[t2].id].ans = min(a[b[t2].id].ans,b[t2].x+b[t2].y-tree.query(b[t2].y));
        tem[k++] = b[t2++];
    }
    for(int i = L; i <= t1-1; i++)
        if(b[i].type == 1) tree.clear(b[i].y);
    while(t1 <= mid) tem[k++] = b[t1++];
    for(int i = L;i <= R;i++) b[i] = tem[i];
}

void solve(int rx,int ry) {
    for(int i = 1; i <= n+q; i++) {
        b[i] = a[i];
        if(rx) b[i].x = len - b[i].x;
        if(ry) b[i].y = len - b[i].y;
    }
    cdq(1,n+q);
}

int main() {
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d",&x,&y);
        a[i].type = 1;
        a[i].id = i;
        a[i].x = ++x;
        a[i].y = ++y;
        len = max(len,max(x,y));
    }
    for(int i = n+1; i <= n+q; i++) {
        scanf("%d%d%d",&opt,&x,&y);
        a[i].type = opt;
        a[i].id = i;
        a[i].x = ++x;
        a[i].y = ++y;
        a[i].ans = INF;
        len = max(len,max(x,y));
    }
    len++;
    solve(0,0),solve(0,1),solve(1,0),solve(1,1);
    for(int i = n+1; i <= n+q; i++)
        if(a[i].type == 2) printf("%d\n",a[i].ans);
    return 0;
}