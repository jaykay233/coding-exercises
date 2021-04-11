#include <bits/stdc++.h>
using namespace std;

const int maxn=100005;
int c[maxn];
int vis[maxn];

int lowbit(int x){
    return x & (-x);
}

void add(int x,int num){
    while(x<=maxn){
        c[x] += num;
        x += lowbit(x);
    }
}

int sum(int x){
    int ret =0 ;
    while(x>0){
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int flag[100000],p[10000];
void init(){
    int i,j,k,tot =0;
    memset(flag,0,sizeof flag);
    for(i=2;i<=100000;i++){
        if(!flag[i]){
            p[++tot] = i;
            for(j=2*i;j<=100000;j+=i){
                flag[j] = 1;
            }
        }
    }
    for(i=2;i<=tot;i++){
        if(p[i]-p[i-1]==2){
            add(p[i],1);
        }
    }
}

int main(){
    init();
    int n;
    while(scanf("%d",&n),n>0){
        if(n==0) printf("0\n");
        else 
        printf("%d\n",sum(n));
    }
    return 0;
}

