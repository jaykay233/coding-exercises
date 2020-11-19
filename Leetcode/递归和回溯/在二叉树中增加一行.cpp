/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int d;
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        this->d = d;
        if(d==1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        dfs(root,v,1);
        return root;
    }

    void dfs(TreeNode* root,int v,int level){
        if(!root) return;
        if(level==d-1){
                TreeNode* n = new TreeNode(v);
                n->left = root->left;
                root->left =n;
            
            
                n = new TreeNode(v);
                n->right = root->right;
                root->right =n;
            
            return;
        }
        dfs(root->left,v,level+1);
        dfs(root->right,v,level+1);
    }
};