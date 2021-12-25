#include <bits/stdc++.h>
#include "template.h"
using namespace std;
const int N = 1000;
int father[N], cnt[N];
Line line[N];

int _find(int x)
{
    if(x==father[x]) return x;
    return _find(father[x]);
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase--){
        int n ;
        scanf("%d",&n);
        int k =1;
        for(int i =1;i<=N;i++){
            father[i] = i;
            cnt[i] = 1;
        }
        while(n--){
            char c[2];
            scanf("%s",c);
            if(c[0] == 'P'){
                scanf("%lf%lf%lf%lf",&line[k].p1.x,&line[k].p1.y, &line[k].p2.x, &line[k].p2.y);
                k++;
                for(int i=1;i<k;i++){
                    if(Cross_segment(line[i].p1, line[i].p2,line[k-1].p1,line[k-1].p2)){
                        int x = _find(k-1);
                        int y = _find(i);
                        if(x!=y){
                            father[x] = y;
                            cnt[y] += cnt[x];
                        }
                    }
                }
            }
            if(c[0] == 'Q'){
                int num;
                scanf("%d",&num);
                printf("%d\n",cnt[_find(num)])
            }
        }
        if(tcase)
            printf("\n");
    }
}