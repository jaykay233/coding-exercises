#include <bits/stdc++.h>
using namespace std;
int t,n;

int pow(int x,int n){
    int base = x;
    int res = 1;
    while(n){
        if(n&1) res *= base;
        res%=10;
        base *= base;
        base %= 10;
        n>>=1;
    }
    return res%10;
}

int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        cout<<pow(n%10,n)<<endl;
    }
    
    return 0;
}