class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        vector<int> res;
        while(cur || !st.empty())
        {
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            if(cur->right==nullptr || cur->right==pre)
            {
                res.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            }
            else {
                st.push(cur);
                cur = cur->right;
            }
        }  
        return res;
    }
};