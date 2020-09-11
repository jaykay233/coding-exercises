#include <bits/stdc++.h>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

const int maxn=510;
int T,N,M,ans;
bool e[maxn][maxn];

int main(){
    T=read();
    while(T--){
        N=read(),M=read();
        memset(e,0,sizeof e);
        for(int i=1;i<=M;i++)
            e[read()][read()]=1;
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                if(e[i][k])
                    for(int j=1;j<=N;j++)
                        e[i][j] |= e[k][j];
            }
        }
        ans=0;
        for(int i=1;i<=N;i++)
            for(int j=i+1;j<=N;j++)
                if(e[i][j] || e[j][i])
                    ans++;
        printf("%d\n",N*(N-1)/2-ans);
    }

    return 0;
}