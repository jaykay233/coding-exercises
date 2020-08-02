#include <bits/stdc++.h>
using namespace std;
int n,m;
//端点固定
const int N = 2010;
int a[N],b[N],c[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    vector<int> cands;

    for(int i =1;i<=n;i++){
        cands.push_back((b[1] - a[i] + m)%m);
    }

    sort(cands.begin(),cands.end());
   
    for(auto t:cands){
        for(int i = 1;i<=n;i++){
            c[i] = (a[i] + t)%m;
        }
        sort(c+1,c+n+1);
        sort(b+1,b+n+1);
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(c[i]!=b[i]){
                ok = false;
                break;
            }
        }
        if(ok){
            printf("%d\n",t);
            break;
        }
    }

    return 0;
}