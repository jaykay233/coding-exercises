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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return result;
    }

    int result =0 ;
    void dfs(TreeNode* root,int up,int low){
        if(root==nullptr) return;
        result = max(result,max(abs(root->val-up),abs(low-root->val)));
        up = max(up,root->val);
        low = min(low,root->val);
        dfs(root->left,up,low);
        dfs(root->right,up,low);
    }
};