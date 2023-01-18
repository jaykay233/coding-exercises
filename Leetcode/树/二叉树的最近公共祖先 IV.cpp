class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(!root) return root;
        if(count(nodes.begin(),nodes.end(), root)) return root;
        TreeNode* l = lowestCommonAncestor(root->left, nodes);
        TreeNode* r = lowestCommonAncestor(root->right, nodes);
        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return nullptr;
    }
};