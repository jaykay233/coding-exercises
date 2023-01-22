/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    struct Node 
    {
        int l,r;
        mutable int v;
        Node(int l,int r=0, int v =0):l(l),r(r),v(v) {}
        bool operator<(const Node& a) const 
        {
            return l < a.l;
        }
    };
    set<Node> s;
    vector<int> res;
    set<Node>::iterator split(int pos) { // 分割操作
        set<Node>::iterator it = s.lower_bound(Node(pos)); // 找到第一个左端点不小于pos的区间
        if (it != s.end() && it->l == pos) return it; // pos本身就是区间左端点,直接返回

        it --; 
        if (it->r < pos) return s.end(); //pos过大,超出了最后一个区间的范围
        int l = it->l, r = it->r, v = it->v;
        s.erase(it), s.insert(Node(l, pos-1, v)); // 将区间[l,r]分为两段[l,pos-1]和[pos,r]
        return s.insert(Node(pos, r, v)).first; // 返回后一个区间的迭代器
    }

    void assign(int l, int r, int x) { // 合并两个区间,并赋值为x
        set<Node>::iterator itr = split(r+1), itl = split(l);
        s.erase(itl, itr);
        s.insert(Node(l, r, x));
    }

    void dfs(TreeNode* root)
    {
        if(!root) return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }

    unordered_map<int,int> mapping;
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        s.insert(Node(0,1e9+1,0));
        sort(res.begin(),res.end());
        vector<int> cp(res);
        for(vector<int>& op: ops)
        {
            cp.push_back(op[1]);
            cp.push_back(op[2]);
        }
        sort(cp.begin(),cp.end());
        cp.erase(unique(cp.begin(),cp.end()),cp.end());
        for(int c:cp)
        {
            int t = mapping.size();
            mapping[c] = t;
        }

        transform(res.begin(),res.end(),res.begin(),[&](int v)
        {
            return mapping[v];
        });

        for(vector<int>& op: ops)
        {
            int tp = op[0];
            int x = mapping[op[1]];
            int y = mapping[op[2]];
            assign(x,y, tp);
        }
        int cnt = 0;
        unordered_map<int,vector<int>::iterator> ub;
        unordered_map<int,vector<int>::iterator> lb;
        for(set<Node>::iterator it = s.begin(); it!=s.end(); it ++)
        {
            int l = it->l;
            int r = it->r;
            if(it->v == 1)
            {
                if(!ub.count(r))
                    ub[r] = upper_bound(res.begin(),res.end(), r);
                if(!lb.count(l))
                    lb[l] = lower_bound(res.begin(),res.end(),l);
                cnt += ub[r] - lb[l];
            }
        }
        return cnt;
    }
};


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
    set<int> st;

    void dfs(TreeNode *node) {
        if (node == nullptr) return;
        st.insert(node->val);
        dfs(node->left);
        dfs(node->right);
    }

public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        int ans = 0;
        for (int i = (int) ops.size() - 1; i >= 0; i--) {
            while (true) {
                auto it = st.lower_bound(ops[i][1]);
                if (it == st.end() || (*it) > ops[i][2]) break;
                st.erase(it);
                if (ops[i][0]) ans++;
            }
        }
        return ans;
    }
};