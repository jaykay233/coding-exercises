class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root);
    }

    bool isleaf(TreeNode* node)
    {
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node)
    {
        int ans = 0;
        if(node->left)
            ans += isleaf(node->left) ? node->left->val : dfs(node->left);
        if(node->right && !isleaf(node->right))
            ans += dfs(node->right);
        return ans;
    }
};