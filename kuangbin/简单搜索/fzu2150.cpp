#include <bits/stdc++.h>
using namespace std;
int T;
char chess[11][11];
int N,M;
bool board[11][11];
bool visit[11][11];
int minans = INT_MAX;

queue<pair<int,int>> q1;
queue<pair<int,int>> q2;
unordered_map<int,int> d;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


int bfs(int x1,int y1,int x2,int y2){
    memset(visit,0,sizeof visit);
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    d.clear();
    q1.push({x1,y1});
    q2.push({x2,y2});
    d[x1*M+y1] = 0;
    d[x2*M+y2] = 0;
    while(!q1.empty() || !q2.empty()){
        if(!q1.empty()){
            auto p = q1.front();q1.pop();
            int x = p.first , y =p.second;
            int dist = d[x*M+y];
            for(int i =0;i<4;i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_<0 || x_>=N || y_<0 || y_>=M) continue;
                if(!visit[x_][y_] && board[x_][y_] &&  !d.count(x_*M+y_)){
                    d[x_*M+y_] = dist + 1;
                    q1.push({x_,y_});
                    visit[x_][y_] = 1;
                }
            }
        }

        if(!q2.empty()){
            auto p = q2.front();q2.pop();
            int x = p.first, y = p.second;
            int dist = d[x*M+y];
            for(int i =0;i<4;i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_<0 || x_>=N || y_<0 || y_>=M) continue;
                if(!visit[x_][y_] && board[x_][y_] && !d.count(x_*M+y_)){
                    d[x_*M+y_] = dist + 1;
                    q2.push({x_,y_});
                    visit[x_][y_] = 1;
                }
            }
        }
    }

    int maxans = 0;
    for(int i =0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]){
                if(!d.count(i*M+j))
                    return INT_MAX;
                maxans = max(maxans,d[i*M+j]);
            }
        }
    }
    return maxans;
}


void print(string s){
    if(s=="board"){
        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }else if(s=="chess"){
        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}


int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&N,&M);
        for(int i =0;i<N;i++){
            scanf("%s",chess[i]);
        }
        // cout<<"chess: "<<endl;
        // print("chess");
        minans = INT_MAX;

        for(int i=0;i<N;i++){
            for(int j =0;j<M;j++){
                if(chess[i][j]=='#') board[i][j] = 1;
                else board[i][j] = 0;
            }
        }

        // cout<<"board: "<<endl;
        // print("board");

        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                for(int k=0;k<N;k++){
                    for(int l=0;l<M;l++){
                        if(board[i][j]==1 && board[k][l]==1){
                            int ans = bfs(i,j,k,l);
                            if(ans==INT_MAX) continue;
                            else if(ans < minans){
                                minans = ans;
                            }
                        }
                    }
                }
            }
        }
        if(minans==INT_MAX){
            printf("Case %d: %d\n",t+1,-1);
        }else{
            printf("Case %d: %d\n",t+1,minans);
        }
    }

    return 0;
}