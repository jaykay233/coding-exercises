#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> digit;
    vector<vector<int>> memo;
    int countDigitOne(int n){
        return solve(n);
    }

    int solve(int n){
        int len = 0;
        digit.assign(64,0);
        while(n){
            digit[++len] = n%10;
            n/=10;
        }
        memo.assign(len,vector<int>(len+1,-1));
        return dfs(len,0,1,1);
    }

    int dfs(int pos,int sm,bool lead,bool limit){
        if(pos==0) return sm;
        if(!lead && !limit && memo[pos][sm]) return memo[pos][sm];
        int up = limit?digit[pos]:9;
        int ret=0;
        for(int i=0;i<=up;i++){
            ret+=dfs(pos-1,sm+(i==1),lead && (i==0), limit && (i==up));
        }
        if(!limit && !lead) memo[pos][sm] = ret;
        return ret;
    }
};

class Solution2{
public:
    int countDigitOne(int n){
        int count =0;
        for(int k=1;k<=n;k*=10){
            int abc = n%k;
            int xyzd = n/k;
            int d = xyzd % 10;
            int xyz = xyzd /10;
            count += xyz * k;
            if(d==1) count+=abc+1;
            else if(d>1) count+=k;
            if(xyz==0) break;
        }
        return count;
    }
}
