/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalsum=0;
    int pathSum(TreeNode* root, int sum) {
        preorder(root,sum);
        return totalsum;
    }

    void dfs(TreeNode* root,int sum){
        if(!root) return;
        if(root->val==sum) totalsum++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }

    void preorder(TreeNode* root,int sum){
        if(!root) return;
        dfs(root,sum);
        preorder(root->left,sum);
        preorder(root->right,sum);
    }
};