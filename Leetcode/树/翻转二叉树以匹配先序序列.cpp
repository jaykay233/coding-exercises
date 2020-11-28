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
    vector<int> flipped;
    int index=0;
    vector<int> voyage;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        this->voyage = voyage;
        dfs(root);
        if(!flipped.empty() && flipped[0]==-1) return {-1};
        return flipped;
    }

    void dfs(TreeNode* node){
        if(node==nullptr) return;
        if(node->val!=voyage[index++]){
            flipped.clear();
            flipped.push_back(-1);
            return;
        }
        if(index<voyage.size() && node->left!=nullptr && node->left->val!=voyage[index]){
            flipped.push_back(node->val);
            dfs(node->right);
            dfs(node->left);
        }else{
            dfs(node->left);
            dfs(node->right);
        }
    }
};