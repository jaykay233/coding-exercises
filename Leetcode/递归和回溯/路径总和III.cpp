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
//https://leetcode-cn.com/problems/path-sum-iii/solution/yi-pian-wen-zhang-jie-jue-suo-you-er-cha-smch/
class Solution {
public:
    int count = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }

    void dfs(TreeNode* root,int sum){
        if(!root) return;
        sum -= root->val;
        if(sum == 0)
            count++;
        dfs(root->left, sum);
        dfs(root->right,sum);
    }
};