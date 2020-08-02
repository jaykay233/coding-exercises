#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int S = 55;
const int M = 1e6+10;
int tr[N*S][26];
int ne[N*S];
int cnt[N*S];
int q[N*S];
int idx;
char str[M];
int T,n;

void insert()
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int t = str[i] - 'a';
        if (!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
    }
    cnt[p] ++ ;
}


void build()
{
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i ++ )
        if (tr[0][i])
            q[ ++ tt] = tr[0][i];

    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = 0; i < 26; i ++ )
        {
            int p = tr[t][i];
            if (!p) tr[t][i] = tr[ne[t]][i];
            else
            {
                ne[p] = tr[ne[t]][i];
                q[ ++ tt] = p;
            }
        }
    }
}

int main(){
    scanf("%d",&T);
    for(int i =0;i<T;i++){
        memset(cnt,0,sizeof cnt);
        memset(tr,0,sizeof tr);
        memset(ne,0,sizeof ne);
        idx= 0;
        scanf("%d",&n);
        for(int i =0;i<n;i++){
            scanf("%s",str);
            insert();
        }
        build();
        scanf("%s",str);
        int res=0;
        for(int i =0,j=0;str[i];i++){
            int t = str[i] - 'a';
            j = tr[j][t];
            int p = j;
            while(p){
                res+=cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}