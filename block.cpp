#include <bits/stdc++.h>
using namespace std;
int n;
int c;
const int MAXN = 10000010;
const int MAXP = 10010;
int x[MAXN];
struct {
  int l,r;
}p[MAXP];
int tot = 0;


void debug(){
  for(int i=1;i<=n;i++){
    printf("%d%d\n", p[i].l,p[i].r);
  }
}

void init(){
  tot = 0;
}

struct {
  int l,r;
  int color;
}tree[MAXN*4];



int main(){
  scanf("%d",&c);
  while(c--){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      scanf("%d%d",&p[i].l,&p[i].r);
      x[tot++] = p[i].l;
      x[tot++] = p[i].r;
    }

    sort(x,x+tot);
    int mm = unique(x,x+tot) - x;
    tot = mm;

    for(int i=1;i<=n;i++){
      p[i].l = lower_bound(x,x+m,p[i].l) - x + 1;
      p[i].r = lower_bound(x,x+m,p[i].r) - x + 1;
    }
    


    debug();
  }


  return 0;
}