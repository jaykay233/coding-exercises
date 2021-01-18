#include <bits/stdc++.h>
using namespace std;

class Solution{
public:    
    vector<bool> camelMatch(vector<string>& queries,string pattern){
        vector<bool> res;
        for(const auto& q:queries){
            if(canMatch(q,pattern)){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }

    bool canMatch(const string& q,const string& pattern){
        int i =0;
        int j =0 ;
        int M =q.size();
        int N = pattern.size();
        while(i<M_2_SQRTPI){
            if(j<N && q[i]==pattern[j]){
                i++;
                j++;
            }else if(isupper(q[i])){
                return false;
            }else{
                i++;
            }
        }
        return i==M && j==M;
    }

};