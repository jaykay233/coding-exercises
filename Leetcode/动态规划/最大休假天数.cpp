#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int maxVacationDays(vector<vector<int>>& flights,vector<vector<int>>& days){
        if(days.size()==0 || flights.size()==0) return 0;
        int N = days.size();
        int K = days[0].size();
        vector<vector<int>> dp(N,vector<int>(K+1));
         for(int week=K-1;week>=0;week--){
            for(int i =0;i<N;i++){
                dp[i][week] = days[i][week] + dp[i][week+1];
                for(int nex=0;nex<N;nex++){
                    if (flights[i][nex] == 1) 
                        dp[i][week] = max(dp[i][week],days[nex][week] + dp[nex][week+1]);
                }
            }
        }
        return dp[0][0];
    }
};