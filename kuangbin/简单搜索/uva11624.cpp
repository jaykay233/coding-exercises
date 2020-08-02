#include <bits/stdc++.h>
using namespace std;
char chess[1005][1005];
int visfire[1005][1005];
int vispeople[1005][1005];
int firetime[1005][1005];
int peopletime[1005][1005];
int dx[4]= {0,1,0,-1};
int dy[4] ={1,0,-1,0};
int T,n,m;

struct node{
    int x,y;
};
node now,net;
queue<node> fire;
queue<node> people;
void judgetime(){
    while(!fire.empty()){
        now = fire.front();fire.pop();
        for(int i =0;i<4;i++){
            int tx = now.x + dx[i];
            int ty = now.y + dy[i];
            if(tx>=0 && tx<n && ty>=0 && ty<m && !visfire[tx][ty] && chess[tx][ty]!='#'){
                net.x = tx;
                net.y = ty;
                visfire[tx][ty]=1;
                fire.push(net);
                firetime[tx][ty] = firetime[now.x][now.y] + 1;
            }
        }
    }    
}   

void bfs(){
    int f= 0;
    while(!people.empty()){
        now = people.front();people.pop();
        if(now.x<=0 || now.x>=n-1 || now.y<=0 || now.y>=m-1){
            f = 1;
            cout<<peopletime[now.x][now.y] + 1 << endl;
            break;
        }
        for(int i =0;i<4;i++){
            net.x = now.x + dx[i];
            net.y = now.y + dy[i];
            if(net.x>=0 && net.x<=n-1 && net.y>=0 && net.y<=m-1 && !vispeople[net.x][net.y] && chess[net.x][net.y]=='.' && 
            peopletime[now.x][now.y] + 1 < firetime[net.x][net.y]){
                vispeople[net.x][net.y] = 1;
                people.push(net);
                peopletime[net.x][net.y] = peopletime[now.x][now.y] + 1;
            }
        }
    }
    if(f==0)
        cout<<"IMPOSSIBLE"<<endl;
}

int main(){
    cin>>T;
    while(T--){
        memset(firetime,0x3f,sizeof firetime);
        memset(peopletime,0x3f,sizeof peopletime);
        memset(visfire,0,sizeof visfire);
        memset(vispeople,0,sizeof vispeople);
        cin>>n>>m;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cin>>chess[i][j];
                if(chess[i][j]=='J'){
                    now.x = i;
                    now.y = j;
                    vispeople[i][j] = 1;
                    people.push(now);
                    peopletime[i][j] = 0;
                }

                if(chess[i][j]=='F'){
                    now.x = i;
                    now.y = j;
                    visfire[i][j] = 1;
                    fire.push(now);
                    firetime[i][j]=0;
                }
            }
        }
        judgetime();
        bfs();
        while(!fire.empty()){
            fire.pop();
        }
        while(!people.empty()){
            people.pop();
        }

    }
}