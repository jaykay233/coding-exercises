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
    int x;
    TreeNode* x_parent;
    int x_depth;
    bool x_found = false;

    // y 的信息
    int y;
    TreeNode* y_parent;
    int y_depth;
    bool y_found = false;

    void update(TreeNode* node, TreeNode* parent, int depth) {
        if (node->val == x) {
            tie(x_parent, x_depth, x_found) = tuple{parent, depth, true};
        }
        else if (node->val == y) {
            tie(y_parent, y_depth, y_found) = tuple{parent, depth, true};
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        update(root, nullptr, 0);
        while (!q.empty()) {
            auto&& [node, depth] = q.front();
            if (node->left) {
                q.emplace(node->left, depth + 1);
                update(node->left, node, depth + 1);
            }
            if (node->right) {
                q.emplace(node->right, depth + 1);
                update(node->right, node, depth + 1);
            }
            if (x_found && y_found) {
                break;
            }
            q.pop();
        }
        return x_depth == y_depth && x_parent != y_parent;
    }
};