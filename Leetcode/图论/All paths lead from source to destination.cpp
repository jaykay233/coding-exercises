#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Two cases it should return false
    //encounter node with no outgoing paths but is not destination
    //it has cycle
    unordered_map<int,set<int>> s;
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> indegree(n);
        for(vector<int> e:edges){
            s[e[0]].insert(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();q.pop();
            if(s[node].empty() && node!=destination) return false;
            for(auto t:s[node]){
                if(indegree[t]<0) return false;
                indegree[t]--;
                q.push(t);
            }
        }
        return true;
    }
};