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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        vector<string> str1;
        dfs(t1, str1);
        vector<string> str2;
        dfs(t2, str2);
        return getIndexOf(str1,str2)!=-1;
    }

    vector<int> getNextArray(vector<string>& match){
        if(match.size()==1) return {-1};
        vector<int> next(match.size());
        next[0] = -1;
        next[1] = 0;
        int preNext =0 ;
        int cur = 2;
        while(cur<match.size()){
            if(match[preNext] == match[cur]){
                next[cur++] = ++preNext;
            }else if(preNext>0){
                preNext = next[preNext];
            }else{
                next[cur++] = 0;
            }
        }
        return next;
    }

    void dfs(TreeNode* t1,vector<string>& str1){
        if(t1==nullptr){
            str1.push_back("null");
            return;
        }
        str1.push_back(to_string(t1->val));
        dfs(t1->left, str1);
        dfs(t1->right, str1);
    }

    int getIndexOf(vector<string>& str1,vector<string>& match){
        if(match.size() > str1.size()) return -1;
        int x =0,y =0;
        vector<int> next = getNextArray(match);
        while(x<str1.size() && y<match.size()){
            if(str1[x] == match[y]){
                x++;y++;
            }else if(next[y]==-1){
                x++;
            }else {
                y = next[y];
            }
        }
        return y == match.size()?x-y:-1;
    }
    
};