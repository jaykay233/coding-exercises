#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double lo = 0, hi = 1e8;
        while(hi - lo > 1e-6){
            double mi = (lo + hi)/2.0;
            if(possible(mi,stations,K))
                hi = mi;
            else
                lo = mi;
        }
        return lo;
    }

    bool possible(double D,vector<int> stations,int K){
        int used =0 ;
        for (int i = 0; i < stations.size() - 1; ++i)
            used += (int) ((stations[i+1] - stations[i]) / D);
        return used <= K;
    }
};