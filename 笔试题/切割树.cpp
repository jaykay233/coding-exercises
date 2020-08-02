#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+10;
int e[N],h[N],ne[N];
int idx;
int color[N];
const int mod = 1e9+7;
long long f[N][2];
int q[N];
long long l[N],r[N];

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] =idx++;
}

void dfs(int u){
    for(int i =h[u];i!=-1;i=ne[i]) dfs(e[i]);
    if(color[u]==0){
        f[u][1] = 1;
        for(int i =h[u];i!=-1;i=ne[i]){
            int j = e[i];
            f[u][1] = f[u][1]%mod * (f[j][0]%mod + f[j][1]%mod) % mod;
        }
    }else if(color[u]==1){
        f[u][0] = 1;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            f[u][0] = (long long)f[u][0] * (f[j][0] + f[j][1]) % mod;
        }

        int k = 0;
        for (int i = h[u]; ~i; i = ne[i]) q[ ++ k] = e[i];

        l[0] = r[k + 1] = 1;
        for (int i = 1; i <= k; i ++ ) l[i] = (long long)l[i - 1] * (f[q[i]][0] + f[q[i]][1]) % mod;
        for (int i = k; i >= 1; i -- ) r[i] = (long long)r[i + 1] * (f[q[i]][0] + f[q[i]][1]) % mod;

        for (int i = 1; i <= k; i ++ )
            f[u][1] = (f[u][1] + (long long)f[q[i]][1] * l[i - 1] % mod * r[i + 1]) % mod;
    }
}

int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int p;
        cin>>p;
        add(p,i);
    }
    for(int i =0;i<n;i++)
        cin>>color[i];

    dfs(0);

    cout<<f[0][1]<<endl;
    return 0;
}