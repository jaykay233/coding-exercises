#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
private:
    bool isGood(vector<int> nums,const string& str){
        for(auto &c : str){
            if(nums[c-'a']==0) return false;
            else nums[c-'a'] --;
        }
        return true;
    }

public: 
    int countCharacters(vector<string>& words,string chars){
        vector<int> records(26,0);
        int res=0;
        for(auto& c:chars) records[c-'a'] ++;
        for(auto& s:words)
            if(isGood(records,s))
                res += s.size();
        return res;
    }
};