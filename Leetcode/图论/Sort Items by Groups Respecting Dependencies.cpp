#include <bits/stdc++.h>
using namespace std;
//先对组排序
//最后对每个组内排序
//思路简单，就是稍微代码量多一些

class Graph {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> indegree;
public:
    Graph() {}
    
    Graph(int n) {
        adj = unordered_map<int, vector<int>>{};
        indegree = unordered_map<int, int>{};
        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
            adj[i] = vector<int>{};
        }
    }
    
    Graph(vector<int> &vec) {
        adj = unordered_map<int, vector<int>>{};
        indegree = unordered_map<int, int>{};
        for (const int &i : vec) {
            indegree[i] = 0;
            adj[i] = vector<int>{};
        }
    }
    
    void addEdge(int from, int to) {
        adj[from].push_back(to);
        indegree[to]++;
    }
    
    vector<int> sort() {
        queue<int> q;
        vector<int> ans;
        for (const auto &p : indegree) {
            if (p.second == 0) q.push(p.first);
        }
        
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            ans.push_back(h);
            for (const auto &i : adj[h]) {
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItems(m, vector<int>{});
        for (int i = 0; i < n; ++i) {
            if (group[i] >= 0) groupItems[group[i]].push_back(i);
            else {
                // Isolated items are put into separate groups.
                group[i] = groupItems.size();
                groupItems.push_back(vector<int>{i});
            }
        }
        
        Graph groupGraph = Graph(groupItems.size());
        vector<Graph> groupItemGraphs(groupItems.size());
        for (int i = 0; i < groupItems.size(); ++i) {
            groupItemGraphs[i] = Graph(groupItems[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (const int &item : beforeItems[i]) {          
                int gi = group[i];
                if (gi == group[item]) {
                    // BeforeItem is in the same group, add edge in the graph of that group.
                    groupItemGraphs[gi].addEdge(item, i);
                } else {
                    // BeforeItem is in a different group, add edge in the graph of groups.
                    groupGraph.addEdge(group[item], gi);
                }
            }
        }

        vector<int> groupOrder = groupGraph.sort();
        vector<int> ans;
        if (groupOrder.size() < groupItems.size()) return ans;
        for (const int &i : groupOrder) {
            vector<int> order = groupItemGraphs[i].sort();
            if (order.size() < groupItems[i].size()) return vector<int>{};
            else for(const int &j : order) ans.push_back(j);
        }
        return ans;
    }
};