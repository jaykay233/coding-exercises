#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
class Solution{
public:
    int maxProfit(vector<int>& prices){
        vector<vector<int>> f(prices.size()+1,vector<int>(3,INT_MIN/2));
        f[0][2] = 0;
        for(int i=1;i<=prices.size();i++){
            f[i][0] = max(f[i-1][0],f[i-1][2] - prices[i-1]);
            f[i][1] = f[i-1][0] + prices[i-1];
            f[i][2] = max(f[i-1][1],f[i-1][2]);
        }
        return max(f[prices.size()][1],f[prices.size()][2]);
    }
};

int main(){


    return 0;
}