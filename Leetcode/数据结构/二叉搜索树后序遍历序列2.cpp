class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> st;
        int root = INT_MAX;
        for(int i =postorder.size()-1;i>=0;i--){
            if(postorder[i]>root) return false;
            while(!st.empty() && postorder[i]<st.top()) {
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
};