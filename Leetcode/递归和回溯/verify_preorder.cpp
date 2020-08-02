#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ans = true;
    bool isValidSerialization(string preorder) {
        preorder+=",";
        int u = 0;
        dfs(preorder,u);
        return ans && u == preorder.size();
    }
    
    void dfs(string& preorder,int& u){
        if(u==preorder.size()){
            ans = false;
            return;
        }
        if(preorder[u]=='#'){
            u+=2;
            return;
        }
        while(u<preorder.size() && preorder[u]!=',') u++; u++;
        dfs(preorder,u);
        dfs(preorder,u);
    }    
};


int main(){


    return 0;
}