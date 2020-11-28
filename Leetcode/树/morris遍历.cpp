/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//中序遍历，morris遍历

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> res;
        while(root){
            if(root->left){
                TreeNode* rightmost = root->left;
                while(rightmost->right && rightmost->right!=root){
                    rightmost = rightmost->right;
                }
                if(rightmost->right!=root){
                    rightmost->right = root;
                    root = root->left;
                }else{
                    res.push_back(root);
                    rightmost->right = nullptr;
                    root = root->right;
                }
            }else{
                res.push_back(root);
                root = root->right;
            }
        }
        res.push_back(nullptr);
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == p) {
                return res[i+1];
            }
        }
        return nullptr;
    }   
};