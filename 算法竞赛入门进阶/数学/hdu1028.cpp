#include <bits/stdc++.h>
using namespace std;

const int MAXN = 121;
int c1[MAXN],c2[MAXN];

int main(){
    int n;
    while(~scanf("%d",&n)){
        int i;
        for(i=0;i<=n;i++){
            c1[i] = 1;
            c2[i] = 0;
        }
        for(i=2;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k+j<=n;k+=i){
                    c2[j+k] += c1[j];
                }
            }
            for(int j=0;j<=n;j++){
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}