#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 20090126;

typedef long long ll;
ll S[N][N];
ll F[N];
ll ans[N];

void calculate(){
    S[0][0] = 1;
    for(int i=1;i<N;i++){
        S[i][i]=1;
        for(int j=1;j<i;j++){
            S[i][j] = ((j*S[i-1][j] % M) + (S[i-1][j-1]%M))%M;
        }
    }
    F[0] = 1;
    for(int i=1;i<N;i++){
        F[i] = ((F[i-1] % M)*(i%M))%M;
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<=i;j++){
            ans[i] = ((ans[i]%M) + (((F[j]%M)*(S[i][j]%M))%M)) % M;
        }
    }
}

int main(){
    calculate();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}