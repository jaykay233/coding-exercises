class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root) return ans;

        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                int row = p.second;
                m[row].push_back(node->val);
                if (node->left) q.push({node->left, row - 1});
                if (node->right) q.push({node->right, row + 1});
            }
        }
        
        map<int, vector<int>>::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++) {
            ans.push_back(iter->second);
        }
        return ans;
    }
};

