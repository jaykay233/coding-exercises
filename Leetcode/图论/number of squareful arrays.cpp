#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,set<int>> graph;
    int cnt= 0 ;
    unordered_set<int> vis;
    vector<int> res;
    bool isSquare(int n){
        int q = sqrt(n);
        return q*q == n;
    }
    
    void dfs(vector<int>& A,int idx){
        if(idx==A.size()) {
            cnt++;
            for(int i =0;i<res.size();i++) cout<<A[res[i]]<<" ";
            cout<<endl;
            return;    
        }
        for(int t:graph[res.back()]){
            if(vis.count(t)) continue;
            if(t>0 && A[t] == A[t-1] && !vis.count(t-1)) continue;
            res.push_back(t);
            vis.insert(t);
            dfs(A,idx+1);
            res.pop_back();
            vis.erase(t);
        }
    }
    
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(),A.end());
        for(int i =0;i<A.size();i++){
            for(int j =i+1;j<A.size();j++){
                if(isSquare(A[i]+A[j])){
                    graph[i].insert(j);
                    graph[j].insert(i);
                }
            }
        }
        for(int i=0;i<A.size();i++){
            if(i>0 && A[i] == A[i-1]) continue;
            res.push_back(i);
            vis.insert(i);
            dfs(A,1);
            res.pop_back();
            vis.erase(i);
        }
        return cnt;
    }
};