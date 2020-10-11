class Solution{
public:  
    void flatten(TreeNode* root){
        if(!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        flatten(root->left);
        root->right = right;
        root->left = NULL;
        while(root->right) root = root->right;
        flatten(root->right);
        root->right = right;
    }
};