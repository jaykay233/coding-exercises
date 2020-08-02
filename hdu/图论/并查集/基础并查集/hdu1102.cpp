#include <bits/stdc++.h>
using namespace std;
int n;
const int N  = 110;
int matrix[N][N];
int m;
int f[N];
struct Edge{
    int cost,x,y;
    Edge(){};
    Edge(int a,int b,int c){
        cost = a;
        x = b;
        y = c;
    }
    bool operator<(const Edge a) const{
        return cost < a.cost;
    }
};
vector<Edge> edges;
int res = 0;


void init(){
    for(int i =0;i<N;i++){
        f[i] = i;
    }
}

int find(int a){
    if(f[a]==a) return a;
    return f[a] = find(f[a]);
}

void merge(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa==fb) return;
    f[fa] = fb;
    return;
}


int main(){
    scanf("%d",&n);
    int a,b;
    init();
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            scanf("%d",&matrix[i][j]);
            if(i<=j && matrix[i][j]>=1 && matrix[i][j]<=1000)
                edges.push_back({matrix[i][j],i,j});
        }
    }
    // for(auto edge:edges){
    //     cout<<edge.cost<<" "<<edge.x<<" "<<edge.y<<endl;
    // }
    scanf("%d",&m);
    
    for(int i =1;i<=m;i++){
        scanf("%d%d",&a,&b);
        // cout<<a<<" "<<b<<endl;
        merge(a,b);
    }

    sort(edges.begin(),edges.end());
    
    for(int i =0;i<edges.size();i++){
        int cost = edges[i].cost;
        // cout<<cost<<endl;
        int x = edges[i].x;
        int y = edges[i].y;
        int fx = find(x);
        int fy = find(y);
        if(fx==fy) continue;
        merge(x,y);
        res+=cost;
    }    

    printf("%d\n",res);

    return 0;
}