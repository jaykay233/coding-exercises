class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) return true;
        stack<int> s;
        s.push(preorder[0]);
        int last_root=0;
        for(int i =1;i<preorder.size();i++){
            if(preorder[i]<preorder[i-1]){
                if(preorder[i]<last_root) return false;
                s.push(preorder[i]);
            }else{
                while(!s.empty() && preorder[i] > s.top()){
                    last_root = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
    }
};