// #include<cstdio>
// #include<cstdlib>
// #include<cstring>
// #include<algorithm>
// using namespace std;
// const int MAX=2000;
// int pre[2*MAX+5];
// bool mark;
// void init(int n){
//     int i;
//     for(i=1;i<=MAX+n;i++) pre[i]=i;
//     mark=true;
// }
// int root(int x){
//     if(x!=pre[x]){
//         pre[x]=root(pre[x]);
//     }
//     return pre[x];
// }
// void merge(int x,int y){
//     int fx,fy;
//     fx=root(x);
//     fy=root(y-MAX);
//     if(fx==fy) {
//         mark=false;
//         return;
//     }
//     fy=root(y);
//     if(fx!=fy){
//         pre[fx]=pre[fy];
//     }
// }
// int main()
// {
//     int t,i,n,m,x,y,k;
//     scanf("%d",&t);
//     for(i=1;i<=t;i++){
//         scanf("%d%d",&n,&m);
//         init(n);
//         for(k=1;k<=m;k++){
//             scanf("%d%d",&x,&y);
//             if(mark){
//                 merge(x,y+MAX);
//                 merge(y,x+MAX);
//             }
//         }
//        printf("Scenario #%d:\n",i);
//         if(mark){
//             printf("No suspicious bugs found!\n");
//         }else{
//             printf("Suspicious bugs found!\n");
//         }
//         printf("\n");
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int f[N],Rank[N],n,k;
bool flag;

void init(){
    flag = false;
    for(int i =0;i<=n;i++)
        f[i] = i, Rank[i] = 0;
}

int find(int x){
    if(x==f[x]) return f[x];
    int t = find(f[x]);
    Rank[x] = (Rank[f[x]] + Rank[x]) & 1;
    f[x] =t;
    return f[x];
}

void Union(int x,int y){
    int a = find(x);
    int b = find(y);
    if(a==b){
        if(Rank[x] == Rank[y])
            flag = true;
        return;
    }
    f[a] = b;
    Rank[a] = (Rank[x] + Rank[y] + 1) & 1;
}




int main(){
    int T,a,b,cas = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        init();
        for(int i =0;i<k;i++){
            scanf("%d%d",&a,&b);
            if(flag) continue;
            Union(a,b);
        }
        printf("Scenario #%d:\n",cas++);
        if(flag)printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        printf("\n");
    }    
    return 0;
}
