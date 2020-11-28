#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    int ans =0;
    int distance;

    vector<int> dfs(TreeNode* root){
        if(root==nullptr) return {};
        if(root->left==nullptr && root->right==nullptr) return {0};
        vector<int> ret;
        auto left = dfs(root->left);
        for(auto& e:left){
            if(++e > distance) continue;
            ret.push_back(e);
        }
        auto right = dfs(root->right);
        for(auto& e:right){
            if(++e>distance) continue;
            ret.push_back(e);
        }
        for(auto l:left){
            for(auto r:right){
                ans += (l+r<=distance);
            }
        }
        return ret;
    }

    int countPairs(TreeNode* root, int distance){
        this->distance = distance;
        dfs(root);
        return ans;
    }
};