//区别另一个树的子树这道题，子树那道题需要调用Same函数
//和这题不同
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        return helper(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

    bool helper(TreeNode* A,TreeNode* B){
        if(!B) return true;
        if(!A) return false;
        if(A->val!=B->val) return false;
        return helper(A->left,B->left) && helper(A->right,B->right);
    }
};