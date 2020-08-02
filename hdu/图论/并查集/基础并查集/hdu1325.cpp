#include <bits/stdc++.h>
using namespace std;
int fa[1005],ru[1005];

int main(){
    set<int> s;
    int a,b,edges,t = 1;
    while(scanf("%d %d",&a,&b)!=EOF){
        if(a<0 && b<0) break;
        if(a==0 && b==0){
            printf("Case %d is a tree.\n",t++);
            continue;
        }
        memset(ru,0,sizeof ru);
        ru[b]++;
        s.clear();
        edges =1 ;
        s.insert(a);s.insert(b);
        while(1){
            scanf("%d %d",&a,&b);
            if(a==0 && b==0)
                break;
            edges++;ru[b]++;
            s.insert(a);s.insert(b);
        }
        int flag = 1;
        for(int i =0;i<1005;i++)
            if(ru[i] >1) flag =0 ;
        if(s.size()==edges+1 && flag)
            printf("Case %d is a tree.\n",t++);
        else
            printf("Case %d is not a tree.\n",t++);
    }

    return 0;
}