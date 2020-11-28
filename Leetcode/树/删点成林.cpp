#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(x),left(nullptr),right(nullptr);
}
class Solution{
public:  
    set<int> del;
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root,vector<int>& to_delete){
        del = set<int>(to_delete.begin(),to_delete.end());
        dfs(root,nullptr);
        if(root)
            res.push_back(root);
        return res;
    }

    void dfs(TreeNode*& root,TreeNode* pre){
        if(!root) return;
        dfs(root->left,root);
        dfs(root->right,root);
        if(del.count(root->val)){
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            root = nullptr;
        }
    }
};