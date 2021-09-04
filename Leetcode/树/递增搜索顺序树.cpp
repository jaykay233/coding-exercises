struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x),left(nullptr), right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(nullptr),right(nullptr) {}
};
class Solution{
public:  
    TreeNode* pre = nullptr;
    TreeNode* increasingBST(TreeNode* root){
        TreeNode* dummy = new TreeNode(-1);
        pre = dummy;
        increasing(root);
        return dummy->right;
    }

    void increasing(TreeNode* root){
        if(root==nullptr) return;
        increasing(root->left);
        pre->right = root;
        root->left = nullptr;
        pre = root;
        increasing(root->right);
    }
};