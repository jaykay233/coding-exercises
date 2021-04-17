#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    double gold = (1+sqrt(5))/2;
    while(cin>>n>>m){
        int a = min(m,n), b = max(m,n);
        double k = (double)(b-a);
        int test = (int)(k*gold);
        if(test==a) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}