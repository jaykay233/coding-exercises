#include <bits/stdc++.h>
using namespace std;
const int maxn = 1003;
int sg[maxn], s[maxn];
int n,m,k,a[102];
void getsg(){
    for(int i=0;i<=maxn;i++){
        memset(s,0,sizeof s);
        for(int j=0;j<n && a[j]<=i;j++)
            for(int k=i-a[j];k>=0;k--)
                s[sg[k]^sg[i-a[j]-k]] = 1;
        for(int j=0;j<=maxn;j++){
            if(!s[j]){
                s[i] = j;
                break;
            }
        }
    }
}

int main(){ 
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        getsg();
        scanf("%d",&m);
        while(m--){
            scanf("%d",&k);
            if(sg[k]) puts("1");
            else puts("2");
        }
    }
    return 0;
}