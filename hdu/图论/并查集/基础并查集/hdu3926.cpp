//hand in hand 同构图
//同构图判定，先判定环，再判定链
#include <bits/stdc++.h>
using namespace std;
const int N  = 10010;
int f[N],Rank[N],n1,m1,n2,m2,pos1,pos2,isCircle[N];

struct Node{
    int num;
    int isCircle;
    friend bool operator<(const Node& a,const Node& b){
        if(a.num!=b.num) return a.num<b.num;
        if(a.isCircle < b.isCircle) return true;;
        return false;
    }
}arr1[N],arr2[N];

void init(int n){
    memset(isCircle,0,sizeof isCircle);
    for(int i =0;i<=n;i++)
        f[i] =i , Rank[i] = 1;
}

int find(int x){
    if(x==f[x]) return x;
    return f[x] = find(f[x]);
}

void merge(int x,int y){
    int a = find(x);
    int b = find(y);
    if(a==b){
        isCircle[a] = 1;
        return;
    }
    Rank[a] += Rank[b];
    f[b] = a;
}

void simulate(int n,int m){
    int a,b;
    init(n);
    for(int i =0;i<m;i++){
        scanf("%d%d",&a,&b);
        merge(a,b);
    }
}

bool judge(){
    if(pos1!=pos2) return false;
    sort(arr1,arr1+pos1);
    sort(arr2,arr2+pos2);
    for(int i =0;i<pos1;i++){
        if(arr1[i].num!=arr2[i].num) return false;
        if(arr1[i].isCircle != arr2[i].isCircle) return false;
    }
    return true;
}


int main(){
    int T,n1,cas = 1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",cas++);
        scanf("%d%d",&n1,&m1);
        simulate(n1,m1);
        pos1 =0 ;
        for(int i =1;i<=n1;i++) if(i==find(i)){
            arr1[pos1].num = Rank[i];
            arr1[pos1++].isCircle = isCircle[i];
        }

        scanf("%d%d",&n2,&m2);
        simulate(n2,m2);
        if(n1!=n2 || m1!=m2){
            puts("NO");
            continue;
        }
        pos2 =0 ;
        for(int i =1;i<=n2;i++) if(i==find(i)){
            arr2[pos2].num = Rank[i];
            arr2[pos2++].isCircle = isCircle[i];
        }
        if(judge()) puts("YES");
        else puts("NO");
    }


    return 0;
}