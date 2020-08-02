#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k;
const int M = 16;
const int N = 16;
int g[M][N];
int temp[M][N];
int res[M][N];
bool ok;

void print(int g[M][N]){
    for(int i=0;i<n;i++){
        for(int j =0;j<k;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            scanf("%d",&g[i][j]);
        }
    }


    for(int i =0;i<(1<<k);i++){
        // memset(temp,0,sizeof temp);
        memcpy(temp,g,sizeof g);
        memset(res,0,sizeof res);
        for(int j =0;j<k;j++){
            if( (i>>j) & 1){
                temp[0][j] = !temp[0][j];
                res[0][j] = 1;
                if(j-1>=0)
                    temp[0][j-1] = !temp[0][j-1];
                if(j+1<k)
                    temp[0][j+1] = !temp[0][j+1];
                temp[1][j] = !temp[1][j];
            }
        }

        // if(i==0)
        //     print(temp);

        ok = true;
        for(int m=1;m<n;m++){
            for(int j=0;j<k;j++){
                if(temp[m-1][j]){
                    res[m][j] = 1;
                    temp[m-1][j] = !temp[m-1][j];
                    temp[m][j] = !temp[m][j];
                    temp[m+1][j] = !temp[m+1][j];
                    temp[m][j-1] = !temp[m][j-1];
                    temp[m][j+1] = !temp[m][j+1];
                }                
            }
        }

        // print(temp);

        for(int m =0;m<k;m++){
            if(temp[n-1][m]) ok = false;
        }    
        if(ok){
            for(int m =0;m<n;m++){
                for(int j =0;j<k;j++){
                    printf("%d ",res[m][j]);
                }
                printf("\n");
            }
            break;
        }
    }
    if(!ok){
        printf("IMPOSSIBLE\n");
    }

    return 0;
}