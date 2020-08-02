#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
const int N = 20;
int node_weight[N];
int g[N][N];
int f[N];
int res[N];
bool flag_dfs[N];
bool flag_prim[N];
int dist[N];


double ans_ratio = 0x3f3f3f3f;

int prim()
{
    memset(flag_prim,false,sizeof flag_prim);
    memset(dist,0x3f,sizeof dist);
    dist[0] =0;
    int res = 0;
    for(int i=0;i<m;i++){
        int t = -1;
        for(int j=0;j<m;j++){
            if(!flag_prim[j] && (t==-1 || dist[j]<dist[t]))
                t = j;
        }
        if(t==-1) return -1;
        res+=dist[t];
        flag_prim[t] = true;
        for(int i=0;i<m;i++) 
            if(!flag_prim[i] && dist[i]>g[f[t]][f[i]])
            dist[i] = min(dist[i],g[f[t]][f[i]]);
    }
    return res;
}

// int prim()
// {
//     int ret=0;
//     memset(flag_prim,false,sizeof(flag_prim));
//     for(int i=1;i<m;i++)
//             dist[i]=g[f[0]][f[i]];
//     flag_prim[0]=1;
//     for(int i=1;i<m;i++)
//     {
//         int v=-1;
//         for(int j=0;j<m;j++)
//             if(!flag_prim[j]&&(v==-1||(dist[v]>dist[j])))
//                 v=j;
//         if(v==-1)
//             return -1;
//         ret+=dist[v];
//         flag_prim[v]=true;
//         for(int j=0;j<m;j++)
//             if(!flag_prim[j]&&dist[j]>g[f[v]][f[j]])
//                     dist[j]=g[f[v]][f[j]];
//     }
//     return ret;
// }



void dfs(int k){
    if(k==m){
        double sum  =0;
        for(int i =0;i<m;i++){
            sum+=node_weight[f[i]];
        }
        double ret = prim();
        if(fabs(ret+1)<1e-5)
            return;
        double ratio = (double) ret / sum;
        if(1e-5<ans_ratio-ratio){
           ans_ratio = ratio;
           for(int i =0;i<m;i++)
                res[i] = f[i]; 
        }
        return;
    }
    else{
        for(int i=0;i<n;i++){
            if(k==0 && i>n-m) break;
            if(k && f[k-1] > i) continue;
            if(!flag_dfs[i]){
                flag_dfs[i] = true;
                f[k] = i;
                dfs(k+1);
                flag_dfs[i] = false;
            }
        }
    }
}


int main(){
    while(~scanf("%d%d",&n,&m) && n && m){
        memset(flag_prim,false,sizeof flag_prim);
        memset(flag_dfs,false,sizeof flag_dfs);
        for(int i=0;i<n;i++)
            scanf("%d",&node_weight[i]);
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                scanf("%d",&g[i][j]);
            }
        }
        // for(int i =0;i<n;i++){
        //     for(int j =0;j<n;j++)
        //         cout<<g[i][j];
        //     cout<<endl;
        // }
        
        ans_ratio = 0x3f3f3f3f;



        dfs(0);
        for(int i =0;i<m-1;i++)
            printf("%d ",res[i]+1);
        printf("%d\n",res[m-1]+1);
    }
    return 0;
}