/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    deque<TreeNode*> dq;
    queue<TreeNode*> q;
    TreeNode* curRoot;
    CBTInserter(TreeNode* root) {
        curRoot = root;
        q.push(root);
        TreeNode* cur = root;
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                cur = q.front(); q.pop();
                if(!cur->left || !cur->right)
                    dq.push_back(cur);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
    }
    
    int insert(int v) {
        dq.push_back(new TreeNode(v));
        TreeNode* t = dq.front();
        if(t->left ==nullptr) t->left = dq.back();
        else if(t->right==nullptr){
            t->right = dq.back();
            dq.pop_front();
        }
        return t->val;
    }
    
    TreeNode* get_root() {
        return curRoot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */