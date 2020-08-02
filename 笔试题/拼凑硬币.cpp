#include <iostream>
#include <cmath>
#include <cstdio>
#include <unordered_map>
using namespace std;

//思路,子集划分,设置小于n的最大幂为m,则：
//若m使用,则相当于dp(n-2^m)有几种用法,否则相当于dp(2^(m+1)-2-n)有几种用法。
//所以答案为两者和。
unordered_map<long long,long long> m;

long long recur(long long n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(n==1) return 1;
    if(m.count(n)) return m[n];
    long long k = (long long )log2(n);
    long long a = n - pow(2,k);
    long long b = pow(2,k+1)-2-n;
    long long res = recur(a) + recur(b);
    cout<<res<<endl;
    m[n] = res;
    return res;
}



int main(){
    long long n;
    cin>>n;
    cout<<recur(n)<<endl;
    return 0;    
}