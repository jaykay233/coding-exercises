#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 5e4+5;
int a[maxn];
int cnt[maxn];
int pos[maxn];
int n,m,k;
struct Q{
    int l,r,k;
}q[maxn];
int ans[maxn];

int res =0 ;

void Add(int n){
    cnt[a[n]]++; res += (cnt[a[n]]*cnt[a[n]])-(cnt[a[n]]-1)*(cnt[a[n]]-1);
}

void Sub(int n){
    cnt[a[n]]--; res+= (cnt[a[n]])*(cnt[a[n]])-(cnt[a[n]]+1)*(cnt[a[n]]+1);
}


int main(){
    cin>>n>>m>>k;
    int sz = sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[i] = i/sz;
    }
    for(int i=0;i<m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].k = i;
    }
    sort(q,q+m,[](Q a,Q b){
        return pos[a.l]==pos[b.l]?a.r<b.r:pos[a.l]<pos[b.l];
    });

    int l = 1, r= 0; //[l,r]

    for(int i=0;i<m;i++){
        while(q[i].l<l) Add(--l);
        while(q[i].r<r) Sub(r--);
        while(q[i].l>l) Sub(l++);
        while(q[i].r>r) Add(++r);
        ans[q[i].k] = res;
    }

    for(int i =0;i<m;i++){
        cout<<ans[i]<<endl;
    }


    return 0;
}