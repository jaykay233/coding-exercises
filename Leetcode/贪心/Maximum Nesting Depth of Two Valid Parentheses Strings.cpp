#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        int z =0 , depth = 0;
        for(int i =0;i<seq.size();i++){
            if(seq[i]=='(') z++;
            else if(seq[i]==')') z--;
            depth = max(depth,z);
        }
        depth = (depth+1)/2;
        z = 0;
        for(int i =0;i<seq.size();i++){
            if(seq[i]=='('){
                z++;
                res[i] = z>depth;
            }else{
                res[i] = z>depth;
                z--;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}