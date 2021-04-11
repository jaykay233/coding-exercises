#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;

int prime[maxn];
bool visit[maxn];
int k =0;
void sieve(int n){
    memset(visit,false,sizeof visit);
    for(int i=2;i<=n;i++){
        if(!visit[i]) {
            prime[k++] = i;
            for(int j=i*i;j<=n;j+=i){
                visit[j] = true;
            }
        }
    }
}

int main(){
    int n,d;
    scanf("%d",&n);
    sieve(20000);
    int res = -1;
    int max_int = -1;
    for(int i=1;i<=n;i++){
        scanf("%d",&d);
        if(res==-1) res = d;
        for(int j=k-1;j>=0;j--){
            if(d%prime[j]==0 && prime[j]>max_int){
                res = d;
                max_int = prime[j];
            }
        }
    }
    cout<<res<<endl;
    return 0;
}