/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(int val, int low, int high){
        if(val>=low && val<=high) return true;
        return false;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==nullptr) return root;
        TreeNode* l = trimBST(root->left, low, high);
        TreeNode* r = trimBST(root->right , low, high);
        if(check(root->val, low, high)){
            root->left = l;
            root->right = r;
            return root;
        }else{
            if(!l) return r;
            if(!r) return l;
            r->left = l;
            return r;
        }
        return nullptr;
    }
};