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
    bool dfs(TreeNode* curr, vector<int>& arr, int arrIndex)
    {
        if (curr == nullptr)
        {
            return false;
        }
        else if (curr->val != arr[arrIndex])
        {
            return false;
        }
        else if (arrIndex == arr.size() - 1)
        {
            return curr->left == nullptr && curr->right == nullptr;
        }

        return dfs(curr->left, arr, arrIndex+1) ||  dfs(curr->right, arr, arrIndex+1);
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }   
};