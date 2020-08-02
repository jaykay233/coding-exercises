#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;
const int N = 1010;
bool st[N];
int primes[N];
int cnt =0 ;
void sieve(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[++cnt] = i;
        for(int j=1;primes[j]*i<=n;j++){
            st[primes[j]*i] = true;
            if(i%primes[j]==0) break;
        }
    }   
}

int main(){
    int n;
    cin>>n;
    sieve(n);
    // cout<<st[n]<<endl;
    int res =0 ;
    for(int i =2;i<=n;i++){
        if(!st[i]) cout<<i<<" ";
    }
    cout<<endl;

    // if(!st[n]) res+=2;
    for(int i =2;i<n/2;i++){
        if(i==n-i && !st[i]){
            res++;
        }
        else if(n-i>=2 && !st[n-i] && !st[i]){
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}