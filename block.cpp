#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
const int M = 10007;

typedef long long ll;
int n,q;
int s[maxn<<2], e[maxn<<2];
ll sum[maxn<<2][3],lazy[maxn<<2][3];


void build(int l,int r,int rt){
  s[rt] = l;
  e[rt] = r;
  sum[rt][0] = sum[rt][1] = sum[rt][2] = 0;
  lazy[rt][0] = lazy[rt][2] = 0;
  lazy[rt][1] = 1;
  if(l==r) return;
  int m = l + r >> 1;
  build(l,m,rt<<1);
  build(m+1,r,rt<<1|1);
}

ll ppow(ll c,int p){
  ll ans = 1;
  for(int i=1;i<=p;i++){
    ans = ans * c;
    ans = ans % M;
  }
  return ans;
}



ll mul(ll a,ll b){
  return ((a % M) * (b%M))%M;
}


void pushdown(int rt,int len){
  int lc = rt<<1, rc = rt<<1|1;
  if(lazy[rt][2]){
    lazy[lc][2] = lazy[rc][2] = lazy[rt][2];
    lazy[lc][1] = lazy[rc][1] = 1;
    lazy[lc][0] = lazy[rc][0] = 0;

    ll tmp = ppow(lazy[rt][2],3);
    sum[lc][2] = mul(tmp,(len-(len>>1)));
    sum[rc][2] = mul(tmp,(len>>1));

    sum[lc][1] = mul(ppow(lazy[rt][2],2),(len-(len>>1)));
    sum[rc][1] = mul(ppow(lazy[rt][2],2),(len>>1));

    sum[lc][0] = mul(lazy[rt][2],(len-(len>>1)));
    sum[rc][0] = mul(lazy[rt][2],(len>>1));

    lazy[rt][2] = 0;
  }
  if(lazy[rt][1]!=1){
    lazy[lc][1] = mul(lazy[lc][1],lazy[rt][1]);
    lazy[rc][1] = mul(lazy[rc][1],lazy[rt][1]);
    if(lazy[lc][0]) lazy[lc][0] = mul(lazy[lc][0],lazy[rt][1]);
    if(lazy[rc][0]) lazy[rc][0] = mul(lazy[rc][0],lazy[rt][1]);

    sum[lc][2] = mul(sum[lc][2],ppow(lazy[rt][1],3));
    sum[rc][2] = mul(sum[rc][2],ppow(lazy[rt][1],3));

    sum[lc][1] = mul(sum[lc][1],ppow(lazy[rt][1],2));
    sum[rc][1] = mul(sum[rc][1],ppow(lazy[rt][1],2));

    sum[lc][0] = mul(sum[lc][0],lazy[rt][1]);
    sum[rc][0] = mul(sum[rc][0],lazy[rt][1]);

    lazy[rt][1] = 1;
  }
  if(lazy[rt][0]){
    lazy[lc][0] += lazy[rt][0];
    lazy[rc][0] += lazy[rt][0];
    ll tmp = ppow(lazy[rt][0],3);
    sum[lc][2] = (sum[lc][2] + (lazy[rt][0] * (sum[lc][1] + lazy[rt][0] * sum[lc][0] % M) % M * 3) % M
            + (len - (len >> 1)) * tmp % M) % M;
    sum[rc][2] = (sum[rc][2] + (lazy[rt][0] * (sum[rc][1] + lazy[rt][0] * sum[rc][0] % M) % M * 3) % M
            + (len >> 1) * tmp % M) % M;
    tmp = ppow(lazy[rt][0],2);
    sum[lc][1] = (sum[lc][1] + 2*(lazy[rt][0] * sum[lc][0]%M)%M + (len-(len>>1))*tmp % M) %M;
    sum[rc][1] = (sum[rc][1] + 2*(lazy[rt][0] * sum[rc][0]%M)%M + (len>>1)*tmp%M)%M;

    sum[lc][0] = (sum[lc][0] + (lazy[rt][0] * (len-(len>>1))%M))%M;
    sum[rc][0] = (sum[rc][0] + (lazy[rt][0] * (len>>1)%M))%M;

    lazy[rt][0] = 0;

  }
}

void pushup(int rt){
  int lc = rt<<1,rt = rt<<1|1;
  sum[rt][0] = (sum[lc][0] + sum[rc][0]) % M;
  sum[rt][1] = (sum[lc][1] + sum[rc][1]) % M;
  sum[rt][2] = (sum[lc][2] + sum[rc][2]) % M;
}


void update(int t,int c,int st,int ed,int rt){
  int len = ed-st+1;
  if(s[rt]==st && e[rt]==ed){
    if(t==2){
      lazy[rt][2] = c;
      lazy[rt][1] = 1;
      lazy[rt][0] = 0;
      sum[rt][0] = (c*(ed-st+1))%M;
      sum[rt][1] = ((c * c % M) * (ed - st + 1)) % M;
      sum[rt][2] = (((c * c) % M) * c % M) * (ed - st + 1) % M;
    }
    else if(t==1){
      lazy[rt][1] = lazy[rt][1] * c % M;
      if(lazy[rt][0]) lazy[rt][0] = lazy[rt][0] * c % M;
      sum[rt][0] = sum[rt][0] * c % M;
      sum[rt][1] = (c * c % M) * sum[rt][1] % M;
      sum[rt][2] = ((c * c % M) * c % M) * sum[rt][2] % M;
    }
    else if(t==0){
      lazy[rt][0] = (lazy[rt][0] + c) % M;
      sum[rt][2] = (sum[rt][2] + (sum[rt][1] + c * sum[rt][0] % M) * 3 * c % M +
              ((((len * c) % M) * c % M) * c % M)) % M;
      sum[rt][1] = (sum[rt][1] + (sum[rt][0] * c % M) * 2 % M + (len * c % M) * c % M) % M;
      sum[rt][0] = (sum[rt][0] + c * len % M) % M;
    }
    return;
  }
  if(s[rt]==e[rt]) return;
  pushdown(rt,e[rt]-s[rt]+1);
  int m = (s[rt] + e[rt]) >> 1;
  if(ed<=m) update(t,c,st,ed,rt<<1);
  else if(st>m) update(t,c,st,ed,rt<<1|1);
  else{
    update(t,c,st,m,rt<<1);
    update(t,c,m+1,ed,rt<<1|1);
  }
  pushup(rt);
}

ll query(int p,int l,int r,int rt){
  if(s[rt]==l && e[rt]==r){
    return sum[rt][p] % M;
  }

  pushdown(rt,e[rt]-s[rt]+1);
  int m = (s[rt] + e[rt]) >> 1;
  ll res = 0;
  if(r<=m) res += query(p,l,r,rt<<1) % M;
  else if(l>m) res += query(p,l,r,rt<<1|1) % M;
  else{
    res += query(p,l,m,rt<<1) % M;
    res += query(p,m+1,r,rt<<1|1) % M;
  }
  return res % M;
}

int main(){
  while(~scanf("%d%d"),&n,&q){
    if(n==0 && q==0) break;
    build(1,n,1);

    while(q--){
      int op,a,b,c;
      scanf("%d%d%d%d",&op,&a,&b,&c);
      if(op==4){
        printf("%lld\n", query(c-1,a,b,1) % M);
      }else{
        update(op-1,c,a,b,1);
      }
    }
  }

  return 0;
}