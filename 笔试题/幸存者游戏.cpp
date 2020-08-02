#include <bits/stdc++.h>
using namespace std;
const int N = 16;
bool st[N];

int main(){ 
    int n,m;
    cin>>n>>m;

    int p=1;
    for(int i=1,r =n;i<=n;i++,r--){
        int k=1;
        for(int j=1;j<=i;j++) k = k*m%r;
        if(k==0) k =r;
        while(true){
            if(!st[p]){
                k--;
                if(!k){
                    st[p] = true;
                    break;
                }
            }
            p++;
            if(p>n) p = 1;
        }
    }
    cout<<p<<endl;

    return 0;
}