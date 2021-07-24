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
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        while(Q.size()){
            int cur_len = Q.size();
            unordered_set<TreeNode*> nxt_level;
            for(int i =0;i<cur_len;i++){
                TreeNode* node = Q.front(); Q.pop();
                if(node->right){
                    if(nxt_level.count(node->right->right)){
                        node->right = nullptr;
                        return root;
                    }else{
                        Q.push(node->right);
                        nxt_level.insert(node->right);
                    }
                }
                if(node->left){
                    if(nxt_level.count(node->left->right)){
                        node->left = nullptr;
                        return root;
                    }else{
                        Q.push(node->left);
                        nxt_level.insert(node->left);
                    }
                }
            }
        }
        return root;
    }
};