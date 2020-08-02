#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 100003 ;


LL qmi(int a,LL k){
    LL res = 1;
    while(k){
        if(k&1) res = (LL) res * a%mod;
        a = (LL) a*a%mod;
        k>>=1;
    }
    return res%mod;
}

int main(){
    LL m,n;
    cin>>m>>n;
    cout<<((qmi(m,n) - (LL)m*qmi(m-1,n-1)+(LL)mod)%mod + mod)%mod<<endl;
    
    return 0;
}