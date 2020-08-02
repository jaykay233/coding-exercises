#include <bits/stdc++.h>
using namespace std;
const int N = 2510;
int n,m;
char a[N],b[N];
int as[N],bs[N];
int f[N][N];
const int mod = 1e9+7;

void getprefix(int sum[],char str[],int k){
    for(int i=1;i<=k;i++){
        if(str[i]=='(') sum[i] = sum[i-1]+1;
        else sum[i] = sum[i-1]-1;
    }
}

int main(){
    cin>>a+1>>b+1;
    int n = strlen(a+1);
    int m = strlen(b+1);
    getprefix(as,a,n);
    getprefix(bs,b,m);
    if(as[n] + bs[m]!=0) puts("0");
    else{
        for(int i =0;i<=n;i++){
            for(int j =0;j<=m;j++){
                if(!i && !j) f[i][j] = 1;
                else{
                    if(as[i]+bs[j]>=0){
                        if(i)  f[i][j] += f[i-1][j];
                        if(j) f[i][j] += f[i][j-1];
                        f[i][j] %= mod;
                    }
                }
            }
        }
        cout<<f[n][m]<<endl;
    }

    return 0;
}