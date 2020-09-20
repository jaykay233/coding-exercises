class Solution{
public:  
    Node* pre = NULL;
    Node* head = NULL;
    Node* treeToDoublyList(Node* root){
        if(!root) return NULL;
        dfs(root);
        head->left=pre;
        pre->right = head;
        return head;
    }

    void dfs(Node* cur){
        if(!cur) return;
        dfs(cur->left);
        if(!pre){
            head = cur;
        }else{
            pre->right = cur;
            cur->left = pre;
        }
        pre=cur;
        dfs(cur->right);
        return;
    }
};