#include <iostream>
#include <cstdio>
using namespace std;
const int L = 31;
const int R = 31;
const int C = 31;

char chess[L][R][C];
int l,r,c;
int sx,sy,sz;
int ex,ey,ez;
int dy[4] = {0,0,1,-1};
int dz[4] = {1,-1,0,0};
int val;

int dfs(int x, int y, int z,int ex,int ey,int ez,int k){
    // cout<<x<<" "<<y<<" "<<z<<" "<<ex<<" "<<ey<<" "<<ez<<endl;
    // cout<<k<<endl;
    if(x==ex && y==ey && z==ez){
        return k;
    }
    for(int i = 0;i<4;i++){
        int delta_y = dy[i];
        int delta_z = dz[i];
        int ny = y + delta_y;
        int nz = z + delta_z;
        if(ny>=0 && ny<r && nz>=0 && nz<c && (chess[x][ny][nz]=='.' || chess[x][ny][nz]=='E')){
            chess[x][ny][nz] = '#';
            if((val = dfs(x,ny,nz,ex,ey,ez,k+1))!=-1) return val;
            chess[x][ny][nz] = '.';
        }
    }
    if(x<ex &&  (chess[x+1][y][z]=='.' || chess[x+1][y][z]=='E')){
        chess[x+1][y][z] = '#';
        if((val = dfs(x+1,y,z,ex,ey,ez,k+1))!=-1) return val;
        chess[x+1][y][z] = '.';
    }

    if(x>ex && (chess[x-1][y][z]=='.' || chess[x-1][y][z]=='E')){
        chess[x-1][y][z] = '#';
        if((val = dfs(x-1,y,z,ex,ey,ez,k+1))!=-1) return val;
        chess[x-1][y][z] = '.';
    }

    return -1;
}


int main(){
    while(true){
        scanf("%d%d%d",&l,&r,&c);
        if(l==0 || r==0 || c==0) break;
        for(int i =0;i<l;i++){
            for(int j = 0;j<r;j++){
                scanf("%s",chess[i][j]);
            }
            getchar();
        }

        for(int i =0;i<l;i++){
            for(int j =0;j<r;j++){
                for(int k=0;k<c;k++){
                    if(chess[i][j][k]=='S'){
                        sx = i;sy = j;sz = k;
                    }
                    if(chess[i][j][k]=='E'){
                        ex = i;ey=j;ez=k;
                    }
                }
            }
        }

        // cout<<ex<<" "<<ey<<" "<<ez<<endl;
        int steps = dfs(sx,sy,sz,ex,ey,ez,0);
        // int steps = -1;
        if(steps==-1){
            printf("Trapped!\n");
        }else{
            printf("Escaped in %d minute(s).\n",steps);
        }
        


    }

    return 0;
}