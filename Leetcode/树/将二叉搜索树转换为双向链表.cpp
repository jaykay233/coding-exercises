class Solution {
public:
    Node* prev = nullptr;
    Node* beg = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        dfs(root);
        beg->left = prev;
        prev->right = beg;
        return beg;
    }

    void dfs(Node* root){
        if(!root) return;
        dfs(root->left);
        if(!prev){
            prev = root;
            beg = root;
        }else{
            prev->right = root;
            root->left = prev;
            prev = root;
        }
        dfs(root->right);
    }
};