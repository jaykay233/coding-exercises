#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution{
public:
    unordered_map<Node*,Node*> m;
    Node* cloneGraph(Node* node){
        if(!node) return m[node] = NULL;
        if(m.count(node)) return m[node];
        else{
            Node* n = new Node(node->val,{});
            m[node] = n;
        }
        for(auto n:node->neighbors){
            m[node]->neighbors.push_back(cloneGraph(n));
        }
        return m[node];
    }
};