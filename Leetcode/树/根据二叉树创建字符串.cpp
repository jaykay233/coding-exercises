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
    string tree2str(TreeNode* root) {
        if(root && !root->left && !root->right) return to_string(root->val);
        string res = to_string(root->val);
        if(root && !root->left && root->right)
            return res + "()" + "(" + tree2str(root->right) + ")";
        else if(root && root->left && !root->right)
            return res + "(" + tree2str(root->left) + ")" ;
        return res + "(" + tree2str(root->left) +")" + "("  + tree2str(root->right) + ")";
    }
};