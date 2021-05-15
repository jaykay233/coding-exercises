#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
char s[maxn];
int sa[maxn],cnt[maxn],t1[maxn],t2[maxn],rk[maxn],height[maxn];

int n;

void calc_sa(){
    int m =127;
    int i,*x=t1,*y=t2;
    for(i=0;i<m;i++) cnt[i] = 0;
    for(i=0;i<n;i++) cnt[x[i]=s[i]]++;
    for(i=n-1;i>=0;i--) sa[--cnt[x[i]]] = i;
    for(int k=1;k<=n;k*=2){
        int p = 0;
        for(i=n-k;i<n;i++) y[p++] = i;
        for(i=0;i<n;i++) if(sa[i]>k) y[p++] = sa[i] - k;
        for(i=0;i<m;i++) cnt[i] = 0;
        for(i=0;i<n;i++) cnt[x[y[i]]]++;
        for(i=n-1;i>=0;i--) sa[--cnt[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1;x[sa[0]] = 0;
        for(i=1;i<n;i++){
            x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k])?p-1:p++;
        }
        if(p>=n) break;
        m = p;
    }
}

int main(){


    return 0;
}