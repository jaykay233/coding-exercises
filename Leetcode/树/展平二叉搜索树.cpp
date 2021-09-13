struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x) , left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution{
public:  
    TreeNode* increasingBST(TreeNode* root){
        stack<TreeNode*> sta;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        while(cur || !sta.empty()){
            while(cur){
                sta.push(cur);
                cur = cur->left;
            }
            cur = sta.top(); sta.pop();
            if(prev == nullptr){
                first = cur;
            }else{
                prev->right = cur;
            }
            cur->left = nullptr;
            prev = cur;
            cur = cur->right;
        }     
        return first;
    }
};