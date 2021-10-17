#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int sa[MAXN];
int rk[MAXN];

void calc_sa(){

}

void get_height(int n){
    int i,j, k =0;
    for(i=0;i<n;i++) rk[sa[i]] = i;
    for(i=0;i<n;i++){
        if(k) k--;
        int j = sa[rk[i-1]];
        while(s[i+k] == s[j+k]) k++;
        height[rk[i]] = k;
    }
}