#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+10;
int a[N],c[N];
int cow[N];
void add(int x,int y){
    while(x<=n){
        c[x] += y;
        x += x&(-x);
    }
}

int get(int x){
    int res =0 ;
    while(x){
        res+=c[x];
        x-=x&(-x);
    }
    return res;
}



int main(){
    cin>>n;
    for(int i = 2;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        add(i,1);
    }
    
    // cout<<a[n]<<endl;
    int res = 0;
    for(int i = n;i>=2;i--){
        int l = 1,r = n;
        int mid;
        while(l<r){
            mid = (l + r)>>1;
            if(get(mid)<a[i]+1) l = mid+1;
            else r = mid;
        }
        // cout<<mid<<endl;
        // cout<<l<<endl;
        cow[i] = l;
        res+=l;
        add(l,-1);
    }
    
    cout<<n*(n+1)/2 - res<<endl;
    for(int i=2;i<=n;i++){
        cout<<cow[i]<<endl;
    }
    
    
    return 0;
}