class Solution {
    bool dfs(TreeNode* rt, ListNode* head) {
        if (head == NULL) return true;
        if (rt == NULL) return false;
        if (rt->val != head->val) return false;
        return dfs(rt->left, head->next) || dfs(rt->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};