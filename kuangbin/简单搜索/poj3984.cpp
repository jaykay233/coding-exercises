#include <bits/stdc++.h>
using namespace std;
int maze[6][6];
queue<pair<int,int>> q;
unordered_map<int,int> d;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
unordered_map<int,int> pre;

int main(){
    for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    q.push({0,0});
    d[0] = 0;
    while(!q.empty()){
        pair<int,int> t = q.front();q.pop();
        int x = t.first, y = t.second;
        if(x == 4 && y ==4){
            break;
        }
        for(int i =0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<5 && ny>=0 && ny<5 && !d.count(nx*5+ny) && maze[nx][ny]==0){
                d[nx*5 + ny] = d[x*5+y] + 1;
                pre[nx*5 + ny] = x*5 + y;
                q.push({nx,ny});
            }
        }
    }
    while(!q.empty()) q.pop();
    vector<pair<int,int>> p;
    int state = 24;
    while(state){
        p.push_back({state/5,state%5});
        state = pre[state];
    }
    p.push_back({0,0});
    reverse(p.begin(),p.end());
    for(int i =0;i<p.size();i++){
        printf("(%d, %d)\n",p[i].first,p[i].second);
    }

    return 0;
}