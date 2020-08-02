//构造割点的图
#include <bits/stdc++.h>
using namespace std;
long long n;
int m,v;

int main(){
    scanf("%lld%d%d",&n,&m,&v);
    long long res = (n-1)*(n-2)/2 + 1;
    if(res <m || m<n-1){
        cout<<-1<<endl;
        return 0;
    }
    int t;
    if(v==1) t=2;
    else t =1;
    cout<<v<<" "<<t<<endl;
    m--;
    for(int i =1;i<=n;i++){
        if(i==t) continue;
        for(int j = i+1;j<=n && m;j++,m--){
            if(j==t) {
                m++;continue;
            }else{
                cout<<i<<" "<<j<<endl;
            }
        }
    }

    return 0;
}