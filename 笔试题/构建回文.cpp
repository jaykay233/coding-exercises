#include <bits/stdc++.h>
using namespace std;
int T;
int n,q;
const int N = 1e5+10;
char s[N];
int f[30][N];


int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>q;
        memset(s,0,sizeof s);
        memset(f,0,sizeof f);
        scanf("%s",s+1);    
        for(int j=1;j<=n;j++){
            for(int k=0;k<26;k++){
                f[k][j] = f[k][j-1] + (s[j] == (k+'A'));
            }
        }
        int cnt =0 ;
        for(int j=1;j<=q;j++){
            int a,b;
            scanf("%d %d",&a,&b);
            bool odd = false;
            bool ok = true;
            for(int k=0;k<26;k++){
                int v1 = f[k][a-1];
                int v2 = f[k][b];
                if((v2-v1)%2){
                    if(odd) {
                        ok = false;
                        break;
                    }else{
                        odd = true;
                    }
                }
            }
            if(ok) cnt++;
        }
        printf("Case #%d: %d\n",i,cnt);
    }
    return 0;
}