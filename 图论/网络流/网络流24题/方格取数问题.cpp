//最小割模型应用
#include <bits/stdc++.h>
using namespace std;
const int M = 110, N =110;
int g[M][N];
int m,n;
const int INF =INT_MAX;
const int MAX_V=1e6;
struct edge{
    int to,cap,rev;     //终点，容量，反向边
};
 
vector<edge> G[MAX_V];  //图的邻接表表示
int level[MAX_V];       //顶点到原点的距离标号
int iter[MAX_V];        //当前弧，在其之前的边已经没有用了
 
 
//增加一条从from到to的容量为cap的边
void add_edge(int from,int to,int cap){
 
    G[from].push_back((edge){to,cap,(int)G[to].size()});
 
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
 
}
 
//通过BFS计算从原点出发的距离标号
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int > que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front(); que.pop();
        for(int i=0;i<G[v].size();i++){
            edge& e=G[v][i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
 
 
//通过DFS寻找增广路
int dfs(int v,int t,int f){
    if(v==t) return f;
    for(int& i=iter[v]; i<G[v].size(); i++){
        edge& e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
 
 
//求解从s到t的最大流
int max_flow(int s,int t){
    int flow=0;
    for(;;){
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}

vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    scanf("%d%d",&m,&n);
    int s = n*m+1;
    int t = n*m+2;
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    int sum = 0;
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if((i+j)%2){
                add_edge(s,i*n+j,g[i][j]);
                for(int k = 0;k<4;k++){
                    int tx = i + dirs[k][0];
                    int ty = j + dirs[k][1];
                    if(tx>=0 && tx<m && ty>=0 && ty<n){
                        add_edge(i*n+j,tx*n+ty,INF);
                    }
                }

            }else{
                add_edge(i*n+j,t,g[i][j]);
            }
            sum += g[i][j];
        }
    }

    cout<<sum - max_flow(s,t)<<endl;

    return 0;
}