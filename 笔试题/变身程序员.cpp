#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 15;

int n,m;
int g[N][N];
int dist[N][N];
vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};

int bfs(){
    queue<PII> que;
    memset(dist,-1,sizeof dist);
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(g[i][j]==2){
                dist[i][j] =0 ;
                que.push(make_pair(i,j));
            }
        }
    }

    while(que.size()){
        auto t = que.front();que.pop();
        int x = t.first, y = t.second, d = dist[x][y];
        for(int i =0;i<4;i++){
            int tx = x + dirs[i][0];
            int ty = y + dirs[i][1];
            if(tx>=0 && tx<n && ty>=0 && ty<m && dist[tx][ty]==-1){
                dist[tx][ty] = d+1;
                que.push({tx,ty});
            }
        }
    }
    int res= 0 ;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(dist[i][j]==-1) return -1;
            res = max(res,dist[i][j]);
        }
    }
    return res;
}

int main(){
    string line;
    while(getline(cin,line)){
        int k =0 ;
        stringstream ssin(line);
        while(ssin>>g[n][k]) k++;
        m = k;
        n++;
    }

    cout<<"ok"<<endl;

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}