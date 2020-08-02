#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 100010;
int types[N],a[N];
vector<int> all[N+1];
int n,m;

struct Node{
    int l,r;
    int s,ps;
}tr[N<<2];

void build(int u,int l,int r){
    tr[u].l = l,tr[u].r = r;
    if(l==r){
        tr[u].s = tr[u].ps = a[l];
        return;
    }

    int mid = (l + r)>>1,left = u<<1, right= left | 1;
    build(left,l,mid),build(right,mid+1,r);
    tr[u].s = tr[left].s + tr[right].s;
    tr[u].ps = max(tr[left].ps, tr[right].ps + tr[left].s);
}

void update(int u,int k,int v){
    if(tr[u].l == tr[u].r){
        a[k] = v;
        tr[u].s = tr[u].ps = v;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >>1, left = u<<1, right = left | 1;
    if(k<=mid) update(left,k,v);
    else update(right,k,v);
    tr[u].s = tr[left].s + tr[right].s ;
    tr[u].ps = max(tr[left].ps, tr[left].s + tr[right].ps);
}


int main(){
    cin>>T;
    for(int i =1;i<=T;i++){
        cin>>n>>m;
        for(int i=0;i<N;i++) all[i].clear();
        for(int i =0;i<n;i++){
            cin>>types[i];
            all[types[i]].push_back(i);
        }

        memset(a,0,sizeof a);
        for(int i =0;i<N;i++){
            for(int j=0;j<m && j<all[i].size();j++) a[all[i][j]] = 1;
            if(all[i].size() >= m + 1) a[all[i][m]]= -m;
        }

        build(1,0,n-1);
        int res = tr[1].ps;
        for(int i=0;i<n;i++){
            update(1,i,0);
            auto indexes =all[types[i]];
            int j = lower_bound(indexes.begin(),indexes.end(),i) - indexes.begin();
            if(j + m < indexes.size()) update(1,indexes[j+m],1);
            if(j + m + 1 < indexes.size()) update(1,indexes[j+m+1],-m);
            res = max(res, tr[1].ps);
        }

        printf("Case #%d: %d\n", i, res);
    }

    return 0;
}