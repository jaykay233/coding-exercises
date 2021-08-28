#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_map<string,int> m;
        for(string word : dict){
            for(int i = 0; i < word.size();i++){
                string mode = word.substr(0,i) + "*" + word.substr(i+1);
                m[mode] ++;
                if(m[mode] == 2){
                    return true;
                }
            }
        }
        return false;
    }
};