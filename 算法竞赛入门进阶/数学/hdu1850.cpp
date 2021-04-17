#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 110;
int a[maxn];
int ans = 0;
int main(){
    while(scanf("%d",&n) && n){
        for(int i=1;i<=n;i++)   
            cin>>a[i];
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum ^= a[i];
        }
        if(sum==0) printf("0\n");
        else{
            ans = 0;
            for(int i=1;i<=n;i++){
                if((sum ^ a[i])<a[i])
                    ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}