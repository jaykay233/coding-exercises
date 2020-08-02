#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int d =gcd(4*n,n+1);
        cout<<4*n/d+1<<endl;
    }
    return 0;
}