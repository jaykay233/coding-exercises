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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isleaf(TreeNode* root){
        return !root->left && !root->right;
    }
    vector<int> res;
    
    void addleaves(TreeNode* root){
        if(!root) return;
        if(isleaf(root)) {
            res.push_back(root->val);
        }
        else{
            if(root->left)
                addleaves(root->left);
            if(root->right)
                addleaves(root->right);
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        if(!isleaf(root)) res.push_back(root->val);
        TreeNode* t = root->left;
        while(t!=nullptr) {
            if(!isleaf(t)) res.push_back(t->val);
            if(t->left) t=t->left;
            else t = t->right;
        }
        addleaves(root);
        
        t = root->right;
        stack<int> st;
        while(t!=nullptr){
            if(!isleaf(t))
                st.push(t->val);
            if(t->right)
                t = t->right;
            else 
                t = t->left;
        }
        while(!st.empty()){
            res.push_back(st.top());st.pop();
        }
        return res;
    }

};