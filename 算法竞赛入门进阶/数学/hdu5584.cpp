#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
    int x,y,T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&x,&y);
        if(x<y) swap(x,y);
        int k = gcd(x,y),cnt=1;
        while(x%(y+k)==0){
            cnt++;
            x=x/(y/k+1);
            if(x<y) swap(x,y);
        }
        printf("Case #%d: %d\n",cas,cnt);
    }
    return 0;
}