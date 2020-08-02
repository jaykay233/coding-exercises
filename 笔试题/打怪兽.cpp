#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 55;
const int M = N*2;
LL d[N],f[N][M];
int p[N];

int main(){
    memset(f,-1,sizeof f);
    f[0][0] =0;
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>d[i];
    }
    for(int i =1;i<=n;i++){
        cin>>p[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            if(j>=p[i] && f[i-1][j-p[i]]!=-1 )f[i][j] = max(f[i][j],f[i-1][j-p[i]]+d[i]);
            if(f[i-1][j]>=d[i]) f[i][j] = max(f[i][j],f[i-1][j]);
        }
    }
    
    int res;
    for(int i =1;i<=2*n;i++){
        if(f[n][i]!=-1){
            res = i;
            break;
        }
    }

    cout<<res<<endl;

    return 0;
}