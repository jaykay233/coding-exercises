#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;

int n,m;
int a[N];
LL tr1[N]; //b[i]
LL tr2[N]; //i*b[i]

int lowbit(int x){
    return x&(-x);
}

void add(LL tr[],int x,LL c){
    for(int i =x;i<=n;i+=lowbit(i)) tr[i]+=c;
}

LL sum(LL tr[],int x){
    LL res =0 ;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}

LL prefix_sum(int x){
    return sum(tr1,x)*(x+1) - sum(tr2,x);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;i++) scanf("%d",&a[i]);
    for(int i =1;i<=n;i++){
        int b = a[i] - a[i-1];
        add(tr1,i,b);
        add(tr2,i,(LL)b*i);
    }

    while(m--){
        char op[2];
        int l,r,d;
        scanf("%s %d %d",op,&l,&r);
        if(*op=='Q'){
            printf("%lld\n",prefix_sum(r) - prefix_sum(l-1));
        }else{
            scanf("%d",&d);
            //a[l] += d
            add(tr1,l,d),add(tr2,l,l*d);
            add(tr2,r+1,-d),add(tr2,r+1,-(r+1)*d);
        }
    }

    return 0;
}