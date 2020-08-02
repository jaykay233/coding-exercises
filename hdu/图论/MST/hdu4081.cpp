#include <bits/stdc++.h>
#define maxn 1005
#define inf 0x3f3f3f3f
using namespace std;
struct Node{
  int x,y,w;
}Edge[maxn];
double Map[maxn][maxn], path[maxn][maxn];
bool vis[maxn], used[maxn][maxn];
double dist[maxn];
int pre[maxn];
int T,n,m;
 
void init(){
  memset(used, false, sizeof(used));
  memset(path, 0, sizeof(path));
  memset(Map, inf, sizeof(Map));
}
 
double dis(int x,int y,int x1,int y1){
  double xx = (x - x1) * (x - x1) + (y - y1) * (y - y1);
  return sqrt(xx);
}
 
double Prim(){
  memset(vis,false,sizeof vis);
  for(int i =1;i<=n;i++){
      dist[i] = Map[1][i];
      pre[i] = 1;
  }
  vis[1] = true;
  double sum  =0;
  for(int i =1;i<n;i++){
      int t = -1;
      for(int j =1;j<=n;j++){
          if(!vis[j] && (t==-1 || dist[t] > dist[j]))
            t = j;
      }
      if(t==-1) return 0x3f3f3f3f;
      sum += dist[t];
      vis[t] = true;
      used[pre[t]][t] =  used[t][pre[t]] = true;
      for(int j =1;j<=n;j++){
          if(vis[j] && j!=t)
            path[j][t] = path[t][j] = max(path[j][pre[t]],dist[t]);
          if(!vis[j]){
              if(dist[j] > Map[t][j]){
                  dist[j] = Map[t][j];
                  pre[j] = t;
              }
          }
      }      
  }

  return sum;
}
 
double SecPrim(double xx){
  double ans = -1;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(used[i][j] == true){
        ans = max(ans, (Edge[i].w + Edge[j].w) / (xx - Map[i][j]));
      }
      else{
        ans = max(ans, (Edge[i].w + Edge[j].w) / (xx - path[i][j]));
      }
    }
  }
  return ans;
}
 
int main()
{
  scanf("%d",&T);
  while(T--){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      scanf("%d%d%d",&Edge[i].x,&Edge[i].y,&Edge[i].w);
    }
    for(int i=1;i<=n;i++){
      Map[i][i] = 0;
      for(int j=i+1;j<=n;j++){
        Map[i][j] = Map[j][i] = dis(Edge[i].x, Edge[i].y, Edge[j].x, Edge[j].y);
      }
    }
    double ans = Prim();
    double ans1 = SecPrim(ans);
    printf("%.2lf\n", ans1);
  }
  return 0;
}