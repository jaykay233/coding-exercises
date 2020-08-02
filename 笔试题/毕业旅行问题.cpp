#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 20; 
int f[1<<N][N];
int g[N][N];

int main(){
    cin>>n;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>g[i][j];
        }
    }
    
    
    memset(f,0x3f/2,sizeof f);
    f[1][0] = 0;
    
    for(int i =0;i<(1<<n);i++){
        for(int j =0;j<n;j++){
            if(i>>j&1){
                int pre = i & ~(1<<j);
                for(int k =0;k<n;k++){
                    if(pre>>k & 1){
                        f[i][j] = min(f[i][j],f[pre][k] + g[k][j]);
                    }
                }
            }
        }
    }
    int res = INT_MAX;
    for(int i =0;i<n;i++){
        res = min(res,f[1<<n][i]+g[i][0]);
    }
    cout<<res<<endl;
    
        
    return 0;
}