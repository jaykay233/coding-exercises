class Solution {
private:
    TreeNode *resNode;

public:
    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        resNode->right = node;
        node->left = nullptr;
        resNode = node;
        inorder(node->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorder(root);
        return dummyNode->right;
    }
};
