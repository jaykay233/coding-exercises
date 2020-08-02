#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M= 21;
int n,m;
int f[N][M];

int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++) f[i][1] = i;
    for(int i=1;i<=m;i++) f[1][i] = 1;

    for(int i=2;i<=n;i++){
        for(int j =2;j<=m;j++){
            f[i][j] = f[i][j-1];
            for(int k=1;k<=i;k++){
                f[i][j] = min(f[i][j],1+max(f[k-1][j-1],f[i-k][j]));
            }
        }
    }
    cout<<f[n][m]<<endl;

    return 0;
}