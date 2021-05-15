#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
char s[MAXN];
int sa[MAXN], rk[MAXN], tmp[MAXN+1];
int n,k;

bool comp_sa(int i,int j){
    if(rk[i]!=rk[j])
        return rk[i] < rk[j];
    else{
        int ri = i + k <=n ? rk[i+k] : -1;
        int rj = j + k <=n ? rk[j+k] : -1;
        return ri < rj;
    }
}

void calc_sa(){
    for(int i =0;i<=n;i++){
        rk[i] = s[i];
        sa[i] = i;
    }
    for(k=1;k<=n;k*=2){
        sort(sa,sa+n,comp_sa);
        tmp[sa[0]] = 0;
        for(int i =0;i<n;i++)
            tmp[sa[i+1]] = tmp[sa[i]] + (comp_sa(sa[i],sa[i+1])?1:0 );
        for(int i =0;i<n;i++)
            rk[i] = tmp[i];
    }
}




int main(){
    while(scanf("%s",s)!=EOF){
        n = strlen(s);
        calc_sa();
        for(int i =0;i<n;i++){
            cout<<sa[i]<<" ";
        }
    }
    return 0;
}