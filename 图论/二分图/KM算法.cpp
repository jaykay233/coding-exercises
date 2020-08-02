#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool visx[N];
bool visy[N];
const int nx = 100;
const int ny = 100;
int lx[N];
int ly[N];
bool match[N];
int weight[N][N];
int delta = 0x3f3f3f3f;
//o(n^4)

bool findpath(int x){
    visx[x] = true;
    for(int y=1;y<=ny;y++){
        if(!visy[y] && lx[x]+ly[y] ==weight[x][y] ){
            visy[y] = true;
            if(!match[y] || findpath(match[y])){
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

void KM(){
    for(int x=1;x<=nx;x++){
        while(true){
            memset(visx,false,sizeof visx);
            memset(visy,false,sizeof visy);
            if(findpath(x)) break;
            else{
                for(int i =1;i<=nx;i++){
                    if(visx[i]){
                        for(int j =1;j<=ny;j++){
                            if(!visy[j])
                                delta = min(delta,lx[i] + ly[j] - weight[i][j]);
                        }
                    }
                }

                for(int i =1;i<=nx;i++)
                    if(visx[i])
                        lx[i] -= delta;
                
                for(int j =1;j<=ny;j++)
                    if(visy[j])
                        ly[j] += delta;

            }
        }

    }
}

int main(){


    return 0;
}