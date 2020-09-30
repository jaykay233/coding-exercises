/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:  
    TreeNode* pre = new TreeNode(-1);
    TreeNode* ans = pre;

    TreeNode* convertBiNode(TreeNode* root){
        dfs(root);
        return ans->right;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        root->left = NULL;
        pre->right = root;
        pre = root;
        dfs(root->right);
    }
}