#include <vector>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:   
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<bool> bikeUsed(bikes.size(),false);
        unordered_map<int,int> memo; 
        return dfs(workers,bikes,0,bikeUsed,memo);
    }
    
    // assign a bike to employee i
    int dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes, int i, vector<bool> &bikeUsed, unordered_map<int,int> &memo){
        if (i==workers.size())  return 0;
        
        int compressed_bikeUsed=compress(bikeUsed);
        if (memo.count(compressed_bikeUsed))
            return memo[compressed_bikeUsed];
        
        int min_dist=INT_MAX;
        for (int j=0;j<bikes.size();++j){
            if (bikeUsed[j]) continue;
            bikeUsed[j] = true;
            min_dist = min(min_dist, dfs(workers,bikes,i+1,bikeUsed,memo) + dist(workers[i],bikes[j]));
            bikeUsed[j] = false;
        }
        return memo[compressed_bikeUsed]=min_dist;
    }
    
    int dist(vector<int> worker, vector<int> bike){
        return abs(worker[0]-bike[0])+abs(worker[1]-bike[1]);
    }
    
    int compress(vector<bool> bikeUsed){
        int res=0;
        for (int i=0;i<bikeUsed.size();++i){
            res <<= 1;
            res |= bikeUsed[i];
        }
        return res;
    }
};