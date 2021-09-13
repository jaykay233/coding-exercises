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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* last = nullptr;
        TreeNode* cur = root;
        vector<int> res;
        while(!st.empty() || cur){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if(cur->right == nullptr || cur->right == last){
                res.push_back(cur->val);
                last = cur;
                cur = nullptr;
                st.pop();
            }
            else cur = cur->right;
        }
        return res;
    }
};