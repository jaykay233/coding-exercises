class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left) return root;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = nullptr;
        root->right = nullptr;
        TreeNode* res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        return res;
    }
};