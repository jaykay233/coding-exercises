#include <bits/stdc++.h>
using namespace std;
int k,n;
const int INF = INT_MAX;
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



int main(){
    scanf("%d%d",&k,&n);
    int s =0,t = n + k + 1;
    int m = 0;
    for(int i =1;i<=k;i++){
        int x;
        scanf("%d",&x);
        m += x;
        add_edge(s,i,x);
    }
    for(int i =1;i<=n;i++){
        int v;
        scanf("%d",&v);
        for(int j =1;j<=v;j++){
            int x;
            scanf("%d",&x);
            add_edge(x,i+k,1);
        }
    }
    for(int i = 1;i<=n;i++){
        add_edge(i+k,t,1);
    }

    int res = max_flow(s,t);

    if(res!=m){
        cout<<"No Solution!"<<endl;
    }else{
        for(int i =1;i<=k;i++){
            printf("%d: ",i);
            for(int j =0;j<G[i].size();j++){
                auto e = G[i][j];
                if(e.cap == 0){
                    cout<<e.to - k <<" ";
                }
            }
            printf("\n");
        }
    }


    return 0;
}