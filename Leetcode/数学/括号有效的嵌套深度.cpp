#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    vector<int> maxDepthAfterSplit(string seq){
        vector<int> res;
        int d = 0;
        for(char c:seq){
            if(c=='('){
                d+=1;
                res.push_back(d%2);
            }else{
                res.push_back(d%2);
                d--;
            }
        }
        return res;
    }
};