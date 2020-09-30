class Solution{
public:  
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root){
        return dfs(root);
    }

    bool dfs(TreeNode* root){
        if(!root) return true;
        if(!dfs(root->left)) return false;
        if(pre!=NULL){
            if(root->val<=pre->val) return false;
        }
        pre = root;
        if(dfs(root->right)) return true;
        return false;
    }
};