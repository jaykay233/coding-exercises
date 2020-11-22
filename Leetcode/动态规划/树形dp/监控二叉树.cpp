struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Status{
    int a;
    int b;
    int c;
};

class Solution{
public:  
    const int inf = 1e5+7;
    Status dfs(TreeNode* root){
        if(!root) return {0,0,inf};
        Status l = dfs(root->left);
        Status r = dfs(root->right);
        Status res;
        res.a = min(l.b,l.c) + min(r.b,r.c);
        res.b = min(l.c + min(r.b,r.c), r.c + min(l.b,l.c));
        res.c = min(l.a,min(l.b,l.c)) + min(r.a,min(r.b,r.c)) + 1;
        return Status{res.a,res.b,res.c}; 
    }

    int minCamera(TreeNode* root){
        Status s = dfs(root);
        return min(s.b,s.c);
    }
};