#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;

int n;
int a[N];
LL f[N];
// 分情况讨论
// 送一个人过去
// 送两个人过去
// 送三个人过去

int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        for(int i =1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        if(n<=2) cout<<a[2]<<endl;
        else{
            memset(f,0,sizeof f);
            for(int i =n;i>=2;i--){
                f[i] = f[i+1] + a[i] + a[2];
                if(i+2<=n+1) f[i] = min(f[i],f[i+2] + a[i+1] + 2*a[3] + a[2]);
                if(i+3<=n+1) f[i] = min(f[i],f[i+3] + 2*a[2] + a[3] + a[4] + a[i+2] + a[4]);
            }
            cout<<a[3] + f[4]<<endl;
        }
    }

    return 0;
}