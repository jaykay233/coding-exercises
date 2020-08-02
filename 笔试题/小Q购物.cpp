#include <bits/stdc++.h>
using namespace std;
int m,n;
const int N = 110; 
int a[N];

int main(){
    cin>>m>>n;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    while(n-1>=0 && a[n-1]>m) n--;
    a[n] = m+1;
    if(a[0]!=1) puts("-1");
    else{
        int res =0 ;
        for(int i =0, s =0;i<n;i++){
            int k = (a[i + 1] - 1 - s + a[i] - 1) / a[i];
            res += k;
            s += k * a[i];
        }

        cout<<res<<endl;
    }


    return 0;
}
