#include <bits/stdc++.h>
using namespace std;
double F[505];
double C[505];
double d[505][505];
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        memset(F,0,sizeof(F));
        memset(C,0,sizeof(C));
        memset(d,0x7f,sizeof(d));
        const int N = prices.size();
        double T = target;
        int TOP = 0;
        for(int i=0;i<N;++i){
            double t = stod(prices[i]);
            C[i] = ceil(t) - t;
            F[i] = t - floor(t);
            T -= floor(t);
            TOP += ceil(t);
        }
        int TT = (int)T;
        if(T < 0 || TT > N || TOP < target){
            return "-1";
        }
        
        d[0][0] = 0;
        for(int i=1;i<=N;++i){
            //i处选floor
            for(int j=0;j<=TT;++j){
                if(d[i-1][j] == 0x7f7f7f7f){
                    d[i][j] = d[i-1][j];    
                }else{
                    d[i][j] = d[i-1][j] + F[i-1];
                }
            }
            //i处选ceil
            for(int j=1;j<=TT;j++){
                if(d[i-1][j-1] == 0x7f7f7f7f){
                    d[i][j] = min(d[i][j],d[i-1][j-1]);    
                }else{
                    d[i][j] = min(d[i][j],d[i-1][j-1] + C[i-1]);
                }
            }
        }
        char s[100];
        sprintf(s,"%.3lf",d[N][TT]);
        return string(s);
    }
};