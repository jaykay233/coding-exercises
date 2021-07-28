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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(path, root, targetSum);
        return res;
    }   

    void dfs(vector<int>& path, TreeNode* root, int target){
        if(!root) return;
        if(root && !root->left && !root->right){
            if(root->val == target){
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        dfs(path,root->left, target - root->val);
        path.pop_back();

        path.push_back(root->val);
        dfs(path, root->right, target - root->val);
        path.pop_back();
    }
};