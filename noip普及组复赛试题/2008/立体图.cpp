#include <bits/stdc++.h>
using namespace std;
const int N = 500;

int n,m;
char box[6][8] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};
char g[N][N];
int h[N][N];

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &h[i][j]);
    
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            g[i][j] = '.';
        }
    }
    int up = N, right =0;
    
    for(int x =0 ;x<n;x++){
        for(int y=0;y<m;y++){
            for(int z=0;z<h[x][y];z++){
                int X = 499 - 2 * (n - 1 - x) - 3 * z;
                int Y = 2 * (n - 1 - x) + 4 * y;
                up = min(up,X-5);
                right= max(right,Y+6);
                for(int a=0;a<6;a++)
                    for(int b=0;b<7;b++)
                        if(box[a][b]!='.')
                            g[X-5+a][Y+b] = box[a][b];
            }        
        }
    }
    
    for (int i = up; i < N; i++)
    {
        for (int j = 0; j <= right; j++) printf("%c", g[i][j]);
        puts("");
    }
    
    
    
    return 0;
}