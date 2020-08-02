#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int min_val = INT_MAX;
int max_val = INT_MIN;
const int N = 1e5+10;
int a[N];
int main(){
    int n;
    for(int i =1;i<=n;i++){
        scanf("%d",&a[i]);
        min_val = min(min_val,a[i]);
        max_val = max(max_val,a[i]);
    }
    if(min_val==a[1] || max_val == a[n]) cout<<1<<endl;
    else cout<<2<<endl;
    return 0;
}