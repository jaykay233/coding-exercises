//康托展开，逆康托展开
#include <bits/stdc++.h>
using namespace std;
const int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int contor(vector<int>& permutation){
    int num =0 ;
    int len = permutation.size();
    int res =0 ;
    for(int i =0;i<permutation.size();i++){
        int counted = 0;
        for(int j = i+1;j<permutation.size();j++){
            if(permutation[i] > permutation[j]){
                counted++;
            }
        }
        res += counted * fact[len-i-1];
    }
    return res;
}

vector<int> revcontor(int bits,int num){
    num --;
    vector<bool> vis(bits+1,false);
    vector<int> permutation(bits,-1);
    int n, residue = num;
    for(int i =0;i<bits;i++){
        n = residue / (fact[bits-i-1]);
        residue = residue % (fact[bits-i-1]);
        for(int j =1;j<=bits;j++){
            if(!vis[j] && !(n--)){
                vis[j] = true;
                permutation[j] = false;
                break;
            }
        }
    }
    return permutation;
}