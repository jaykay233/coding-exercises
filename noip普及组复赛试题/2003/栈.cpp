//卡特兰数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 40;
int n;
LL c[N][N];

int main(){
    cin>>n;
    for(int j = 0;j<=2*n;j++){
        for(int i=j;i<=2*n;i++){
            if(!j) c[i][j] = 1;
            else c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    
    cout<<c[2*n][n]/(n+1)<<endl;
    
    return 0;
}