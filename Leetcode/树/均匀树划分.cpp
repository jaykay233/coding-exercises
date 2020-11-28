class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> mp;
        auto sum = dfs(root, mp);
        if (sum == 0) {
            return mp[0] > 1;
        }

        return (sum % 2 == 0) && mp.count(sum / 2);
    }

private:
    int dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root) {
            return 0;
        }

        auto sum = root->val;
        sum += dfs(root->left, mp);
        sum += dfs(root->right, mp);
        mp[sum]++;

        return sum;
    }
};