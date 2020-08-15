#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int Lmax=0;
        int Rmax=0;
        int res=0;
        for(int i=1;i<A.size();i++)
            A[i]+=A[i-1];
        Lmax=A[L-1];
        Rmax=A[M-1];
        res=A[L+M-1];
        for(int i=L+M;i<A.size();i++){
            Lmax=max(Lmax,A[i-M]-A[i-M-L]);
            Rmax=max(Rmax,A[i-L]-A[i-L-M]);
            res=max(res,Lmax+A[i]-A[i-M]);
            res=max(res,Rmax+A[i]-A[i-L]);
        }
        return res;
    }
};