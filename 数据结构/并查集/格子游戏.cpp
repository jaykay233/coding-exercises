#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 40010;
int p[N];

int find(int a){
    if(p[a]!=a) p[a] =find(p[a]);
    return p[a];
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i =0;i<N;i++) p[i] = i;
    int j = m+1;
    for(int i =1;i<=m;i++){
        int x,y;char C[2];

        scanf("%d %d %s",&x,&y,C);
        x -- ; y--;
        int point = x* n + y;
        int point2;
        if(C[0]=='D'){
            point2 = (x+1) * n +y;
        }else{
            point2 = x*n+y+1;
        }
        int f1 = find(point);
        int f2 = find(point2);
        if(f1==f2) {
            j = i;
            cout<<i<<endl;
            break;
        }else{
            p[f1] = f2;
        }
    }
    if(j>m) puts("draw");
    
    return 0;
}