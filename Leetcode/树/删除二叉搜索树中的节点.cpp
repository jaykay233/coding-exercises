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
    int successor(TreeNode* root){
        TreeNode* node = root->right;
        while(node && node->left) node = node->left;
        return node->val;
    }

    int predecessor(TreeNode* root){
        TreeNode* node = root->left;
        while(node && node->right) node = node->right;
        return node->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(key >root->val) root->right = deleteNode(root->right,key);
        else if(key<root->val) root->left = deleteNode(root->left,key);
        else{
            if(root->left==nullptr && root->right ==nullptr) root = nullptr;
            else if(root->right!=nullptr){
                root->val = successor(root);
                root->right = deleteNode(root->right,root->val);
            }else if(root->left!=nullptr){
                root->val = predecessor(root);
                root->left = deleteNode(root->left,root->val);
            }
        }
        return root;
    }
};