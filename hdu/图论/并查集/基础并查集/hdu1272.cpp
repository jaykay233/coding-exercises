#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int f[N];
bool flag[N];
void init(){
    for(int i =0;i<N;i++){
        f[i] = i;
    }
    memset(flag,false,sizeof flag);
}

int find(int a){
    if(f[a] == a) return a;
    return f[a] = find(f[a]);
}

void merge(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa!=fb)
        f[fa] = fb;
    return;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)){
        if(a==-1 && b==-1) break;
        init();
        int FLAG = 0;
        while(true){
            if(a==0 && b==0) break;
            if(find(a) == find(b)) FLAG = 1;
            merge(a,b);
            flag[a] = flag[b] = true;
            scanf("%d%d",&a,&b);
        }
        if(FLAG==1){
            printf("No\n");
        }else{
            int sum =0;
            for(int i =0;i<N;i++)
                if(flag[i] && f[i] ==i ) sum++;
            if(sum>1)
                printf("No\n");
            else 
                printf("Yes\n");
        }
    }

    return 0;
}