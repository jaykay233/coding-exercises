/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res= INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int l = max(dfs(root->left),0);
        int r = max(dfs(root->right),0);
        res = max(res,root->val + l + r);
        return root->val + max(l,r);
    }
};