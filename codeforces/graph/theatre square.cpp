//https://codeforces.com/problemset/problem/1/A
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,a;
    scanf("%lld %lld %lld",&n,&m,&a);
    long long x = (n+a-1)/a;
    long long y = (m+a-1)/a;
    cout<<x*y<<endl;
    return 0;
}