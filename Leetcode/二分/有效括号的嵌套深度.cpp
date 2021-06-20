#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int d = 0;
        for(int i =0;i<seq.size();i++){
            if(seq[i]=='('){
                d+=1;
                ans.push_back(d%2);
            }else{
                ans.push_back(d%2);
                d-=1;
            }
        }
        return ans;
    }
};