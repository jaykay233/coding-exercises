class Solution {
public:
    bool findp = false;
    bool findq = false;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = lowestCommonAncestor2(root, p, q);
        if(!(findp && findq)) return nullptr;
        return node;
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return root;

        TreeNode* l = lowestCommonAncestor2(root->left, p, q);
        TreeNode* r = lowestCommonAncestor2(root->right, p, q);
        if(l && r) return root;

        // 后序位置进行完全搜索
        if(root->val == q->val || root->val == p->val){
            if(root->val == q->val) findq = true;
            if(root->val == p->val) findp = true;
            return root;
        }
    
        return l ? l : r;
    }
};