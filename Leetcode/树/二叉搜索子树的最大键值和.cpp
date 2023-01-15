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
    struct ResType
    {
        int min_val;
        int max_val;
        bool isSearchBinaryTree;
        int subSum;
        ResType()
        {
            subSum = 0;
            min_val = INT_MAX;
            max_val = INT_MIN;
            isSearchBinaryTree = true;
        }
        ResType(int m1, int m2, bool isSearch, int sum):min_val(m1),max_val(m2),isSearchBinaryTree(isSearch),subSum(sum)
        {

        }
    };
    int max_sum = 0;
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return max_sum;
    }

    ResType dfs(TreeNode* root)
    {
        if(root && !root->left && !root->right)
        {
            max_sum = max(max_sum, root->val);
            return {root->val, root->val, true, root->val};
        }
        ResType res;
        res.subSum = root->val;
        if(root->left)
        {
            ResType l = dfs(root->left);
            res.min_val = min(res.min_val, min(l.min_val, root->val));
            res.max_val = max(res.max_val, max(l.max_val, root->val));
            if(root->val <= l.max_val || !l.isSearchBinaryTree)
                res.isSearchBinaryTree = false;
            res.subSum += l.subSum;
            if(l.isSearchBinaryTree)
                max_sum = max(max_sum, l.subSum);
        }
        if(root->right)
        {
            ResType r = dfs(root->right);
            res.min_val = min(res.min_val, min(r.min_val, root->val));
            res.max_val = max(res.max_val, max(r.max_val, root->val));
            if(root->val >= r.min_val || !r.isSearchBinaryTree)
                res.isSearchBinaryTree = false;
            res.subSum += r.subSum;
            if(r.isSearchBinaryTree)
                max_sum = max(max_sum, r.subSum);
        }   
        if(res.isSearchBinaryTree && max_sum < res.subSum){
            max_sum = res.subSum;
        }
        
        return res;
    }  
};