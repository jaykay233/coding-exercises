class Solution2 {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        bool ok = flip(root, voyage, 0, voyage.size()-1, res);
        if(!ok) return {-1};    
        return res;
    }

    bool flip(TreeNode* root, vector<int>& voyage, int l,int r, vector<int>& res){
        if(l > r) return true;
        if(l == r) {
            if(!root) return false;
            return root->val == voyage[l];
        }
        if(!root) return false;
        if(root->val!=voyage[l]) return false;
        l ++;
        if(root->left && root->right)
        {
            int left_val = root->left->val;
            if(left_val!=voyage[l]){
                TreeNode* tmp = root->left;
                root->left = root->right;
                root->right = tmp;
                res.push_back(root->val);
            }
            int val = root->right->val;
            int mid = -1;
            for(int i = l;i<=r;i++){
                if(voyage[i] == val){
                    mid = i;
                    break;
                }
            }
            if(mid == -1) return false;
            return flip(root->left, voyage, l, mid-1, res) && flip(root->right, voyage, mid, r, res);
        }
        if(root->right)
            return flip(root->right, voyage, l , r, res);
        return flip(root->left, voyage, l, r, res);
    }
};

class Solution {
public:
    int i =0;
    vector<int> res;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(dfs(root,voyage))
            return res;
        return {-1};
    }
    bool dfs(TreeNode* root, vector<int>& voyage)
    {
        if(!root) return true;
        if(root->val != voyage[i]) return false;
        i ++;
        if(dfs(root->left, voyage) && dfs(root->right, voyage)) return true;
        if(dfs(root->right, voyage) && dfs(root->left, voyage)){
            res.push_back(root->val);
            return true;
        }
        return false;
    }
};