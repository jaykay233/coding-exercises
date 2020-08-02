
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        double inorder = -3e10;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();st.pop();
            if(root->val <= inorder) return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};