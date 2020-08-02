#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 200010;
struct seg{
    int l,r,sum;
}segs[N<<2];
vector<pair<int,int>> v;
int ans[N];

void build(int l,int r,int node){
    segs[node].l = l;
    segs[node].r = r;
    segs[node].sum = r - l + 1;
    if(l==r) return;    
    int m = (l + r)>>1;
    build(l,m,node<<1);
    build(m+1,r,node<<1|1);
    segs[node].sum = segs[node<<1].sum + segs[node<<1|1].sum;
    return;
}

void modify(int x,int cnt,int node){
    if(segs[node].l == segs[node].r){
        segs[node].sum += cnt;
        return;
    }
    int m = (segs[node].l + segs[node].r)/2;
    if(m>=x) modify(x,cnt,node<<1);
    else modify(x,cnt,node<<1|1);
    segs[node].sum = segs[node<<1].sum + segs[node<<1|1].sum;
}

int query(int val,int node){
    if(segs[node].l == segs[node].r) return segs[node].l;
    int tmp = segs[node<<1].sum;
    if(tmp>=val) return query(val,node<<1);
    else return query(val - tmp,node<<1|1);
}

void print(int node){
    cout<<segs[node].l<<"-"<<segs[node].r<<" "<<segs[node].sum<<endl;
    if(segs[node].l == segs[node].r) return;
    print(node<<1);
    print(node<<1|1);
}


int main(){
    while(scanf("%d",&n)==1){
        v.clear();
        memset(segs,0,sizeof segs);
        build(0,n-1,1);
        // print(1);

        for(int i =1;i<=n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }

        for(int i =v.size()-1;i>=0;i--){
            pair<int,int> t = v[i];
            // cout<<t.first<<" "<<t.second<<endl;
            int x = query(t.first+1,1);
            // cout<<x<<endl;
            modify(x,-1,1);
            ans[x] = t.second;
        }
        for(int i =0;i<n;i++) cout<<ans[i]<<' ';
        cout<<endl;
    }

    return 0;
}