/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        if(!p) return NULL;
        if(p->right) {
            TreeNode* temp = p->right;
            while(temp && temp->left)
                temp = temp->left;
            return temp;
        }else{
            while(p->father && p->father->right == p){
                p = p->father;
            }
            return p->father;
        }
        return NULL;
    }
};