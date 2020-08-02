#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int n,m,k;
int a[N][N];
int minv[N][N],maxv[N][N];

int main(){
    int T;
    scanf("%d",&T);
    for(int C=1;C<=T;C++){
        scanf("%d%d%d",&n,&m,&k);
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                scanf("%d",&a[i][j]);
                minv[i][j] = maxv[i][j] = a[i][j];
            }
        }

        int res = n;
        for(int len=2;len<=m;len++){
            for(int i =1;i+len-1<=m;i++){
                for(int j=1,s=0;j<=n;j++){
                    int &mn = minv[j][i];
                    int &mx = maxv[j][i];
                    mn = min(mn,a[j][i+len-1]);
                    mx = max(mx,a[j][i+len-1]);

                    if(mx-mn<=k){
                        s++;
                        res = max(res,s*len);
                    }else s =0 ;
                }
            }
        }

        printf("Case #%d: %d\n",C,res);

    }
    return 0;
}