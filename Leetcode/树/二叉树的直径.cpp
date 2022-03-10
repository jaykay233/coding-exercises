class Solution {
public:
    int res =0 ;
    int diameterOfBinaryTree(TreeNode* root) {
        getLen(root);
        return max(0,res-1);
    }

    int getLen(TreeNode* root){
        if(root==nullptr) return 0;
        int l = getLen(root->left);
        int r = getLen(root->right);
        res = max(1 + l + r, res);
        return max(l,r) + 1;
    }
};