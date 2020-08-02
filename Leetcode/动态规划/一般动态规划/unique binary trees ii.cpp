/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <iostream>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        vector<vector<vector<TreeNode*>>> memo(n,vector<vector<TreeNode*>>(n));
        return helper(1,n,memo);
    }
    
    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& memo){
        if(start>end) return {NULL};
        if(!memo[start-1][end-1].empty()) return memo[start-1][end-1];
        vector<TreeNode*> res;
        for(int i = start;i<=end;i++){
            vector<TreeNode*> l = helper(start,i-1,memo);
            vector<TreeNode*> r = helper(i+1,end,memo);
            for(auto li:l){
                for(auto ri:r){
                    TreeNode* node = new TreeNode(i);
                    node->left = li;
                    node->right = ri;
                    res.push_back(node);
                }
            }
        }
        return memo[start-1][end-1] = res;
    }
    
};