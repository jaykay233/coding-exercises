struct Node{
    Node* left;
    Node* right;
    int value ;
    int sz;
    int ans;
    Node(int val):left(NULL),right(NULL),value(val),sz(1),ans(0) {}

    void insert(int val){
        Node* cur = this;
        while(true){
            ++cur->sz;
            if(val < cur->value){
                if(!cur->left){
                    cur->left = new Node(val);
                    return;
                }
                cur=cur->left;
            }else{
                if(!cur->right){
                    cur->right = new Node(val);
                    return;
                }
                cur=cur->right;
            }
        }
    }
};


class Solution {
public:
    static constexpr int mod = 1000000007;
    vector<vector<int>> c;
    void dfs(Node* node){
        if(!node) return;
        dfs(node->left);
        dfs(node->right);
        int lsize = node->left?node->left->sz:0;
        int rsize = node->right?node->right->sz:0;
        int lans = node->left?node->left->ans:1;
        int rans = node->right?node->right->ans:1;
        node->ans = (long long)c[lsize + rsize][lsize] % mod * lans % mod * rans % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        c.assign(n,vector<int>(n));
        c[0][0] = 1;
        for(int i=1;i<n;i++){
            c[i][0] = 1;
            for(int j=1;j<n;j++){
                c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
            }
        }
        Node* root = new Node(nums[0]);
        for(int i=1;i<nums.size();i++){
            root->insert(nums[i]);
        }
        dfs(root);
        return (root->ans-1+mod)%mod;
    }
};