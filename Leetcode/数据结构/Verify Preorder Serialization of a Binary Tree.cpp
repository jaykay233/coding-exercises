#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> split(string preorder){
        vector<string> res;
        string item;
        stringstream ss(preorder);
        while(getline(ss,item,',')){
            res.push_back(item);
        }
        return res;
    }
    bool isValidSerialization(string preorder) {
        vector<string> res= split(preorder);
        int slots = 1;
        for(string node: res){
            slots -= 1;
            if(slots<0)
                return false;
            if(node!="#")
                slots += 2;
        }
        return slots==0;
    }
};