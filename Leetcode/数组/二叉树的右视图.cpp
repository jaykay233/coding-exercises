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
    vector<int> res;
    unordered_map<int,int> m;
    int max_depth = 0;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,1);
        for(int i = 1; i<=max_depth;i++){
            res.push_back(m[i]);
        }
        return res;
    }

    void dfs(TreeNode* root,int depth){
        if(!root) return;
        if(depth > max_depth){
            m[depth] = root->val;
            max_depth = depth;
        }
        dfs(root->right, depth+1);
        dfs(root->left, depth+1);
    }
};