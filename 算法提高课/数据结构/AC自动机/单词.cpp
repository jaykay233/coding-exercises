#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int tr[N][26];
int q[N],f[N];
int ne[N];
int id[210];
int n;
int idx;
char str[N];

void insert(int x){
    int p = 0;
    for(int i =0;str[i];i++){
        int t = str[i] - 'a';
        if(!tr[p][t]) tr[p][t] = ++idx;
        p = tr[p][t];
        f[p] ++;
    }
    id[x] = p;
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
            int &p = tr[t][i];
            if (!p) p = tr[ne[t]][i];
            else
            {
                ne[p] = tr[ne[t]][i];
                q[ ++ tt] = p;
            }
        }
    }
}


int main(){
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%s",str);
        insert(i);
    }
    
    build();
    for(int i = idx-1;i>=0;i--) f[ne[q[i]]] += f[q[i]];
    for(int i = 0;i<n;i++) printf("%d\n",f[id[i]]);
    
    return 0;
}