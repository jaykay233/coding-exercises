#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;
int n,m;
int a[N];
LL tr[N];

int lowbit(int x){
    return x&(-x);
}

void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}

LL sum(int x){
    LL res =0 ;
    for(int i =x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;i++) scanf("%d",&a[i]);
    for(int i =1;i<=n;i++) add(i,a[i] - a[i-1]);
    for(int i =0;i<m;i++){
        char op[2];
        int l,r,d;
        scanf("%s%d",op,&l);
        if(*op=='C'){
            scanf("%d%d",&r,&d);
            add(l,d), add(r+1,-d);
        }else{
            printf("%lld\n",sum(l));
        }
    }

    return 0;
}