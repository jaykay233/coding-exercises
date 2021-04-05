#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

const int MAXN =2 ;
const int MOD = 10000;

struct Matrix{
    int m[MAXN][MAXN];
    Matrix(){
        memset(m,0,sizeof m);
    }
};

Matrix Multi(Matrix a,Matrix b){
    Matrix res;
    for(int i =0;i<MAXN;i++){
        for(int j =0;j<MAXN;j++){
            for(int k =0;k<MAXN;k++){
                res.m[i][j] += a.m[i][k] * b.m[k][j];
                res.m[i][j] %= MOD;
            }
        }
    }
    return res;
}

Matrix fastfm(Matrix a,int n){
    Matrix res;
    for(int i =0;i<MAXN;i++)
        res.m[i][i] = 1;
    while(n){
        if(n&1) res = Multi(res,a);
        a = Multi(a,a);
        n>>=1;
    }
    return res;
}





int main(){
    int n;
    while(~scanf("%d",&n) && (n!=-1)){
        if(n==0) printf("0\n");
        else if(n==1) printf("1\n");
        else{
            Matrix res;
            res.m[0][0] = 1;res.m[0][1] = 1;res.m[1][0]=1;res.m[1][1]=0;
            res = fastfm(res,n);
            printf("%d\n",res.m[0][1]);
        }
    }

    return 0;
}

