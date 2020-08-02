#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, m, L, R;
vector<int> val[N];
int lch[N << 2], rch[N << 2], Max[N << 2], lazy[N << 2];
inline void update(int x, int v) {
    lazy[x] += v; Max[x] += v;
}
inline void pushup(int x) {Max[x] = max(Max[x << 1], Max[x << 1 | 1]);}
inline void pushdown(int x) {
    if(lazy[x]) {
        update(x << 1, lazy[x]); update(x << 1 | 1, lazy[x]); lazy[x] = 0; 
    }
}
void build(int x,int l, int r) {
    lch[x] = l; rch[x] = r;
    if(l == r) {
        Max[x] = l; return;
    }
    int mid = (l + r) / 2;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
    pushup(x);
}
void update(int x, int l, int r, int v) {
    if(l <= lch[x] && rch[x] <= r) {
        update(x, v); return;
    }
    pushdown(x);
    int mid = (lch[x] + rch[x]) / 2;
    if(r <= mid) update(x << 1, l, r, v);
    else if(l > mid) update(x << 1 | 1, l, r, v);
    else update(x << 1, l, mid, v), update(x << 1 | 1, mid + 1, r, v);
    pushup(x);
}
int query(int x, int l, int r) {
    if(l <= lch[x] && rch[x] <= r) {
        return Max[x];
    }
    pushdown(x);
    int mid = (lch[x] + rch[x]) / 2;
    if(r <= mid) return query(x << 1, l, r);
    else if(l > mid) return query(x << 1 | 1, l, r);
    else return max(query(x << 1, l, mid), query(x << 1 | 1, mid + 1, r));
}
int ans = 0;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &L, &R); val[L].push_back(R);
    }
    build(1, 0, m + 1);
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j < val[i].size(); ++j) {
            update(1, 0, val[i][j], 1);
        }
        ans = max(ans, query(1, i + 1, m + 1) - m - i - 1);
    }
    printf("%d\n", max(ans, n - m));
    return 0;
}