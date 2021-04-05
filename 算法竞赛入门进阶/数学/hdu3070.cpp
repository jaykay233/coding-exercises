#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2;

struct Matrix{
    int m[MAXN][MAXN];
    Matrix(){
        memset(m,0,sizeof m);
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

    Matrix Multi(Matrix a,Matrix b){
        Matrix res;
        for(int i =0;i<MAXN;i++){
            for(int j =0;j<MAXN;j++){
                for(int k =0;k<MAXN;k++){
                    res.m[i][j] += a.m[i][k] * b.m[k][j];
                }
            }
        }
        return res;
    }
};


int main(){


    return 0;
}