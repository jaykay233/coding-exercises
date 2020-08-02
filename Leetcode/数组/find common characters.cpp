#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char,int> freq1;
        for(char c:A[0]){
            freq1[c]++;
        }
        for(int i=1;i<A.size();i++){
            unordered_map<char,int> freq2;
            string a = A[i];
            for(char c:a){
                if(freq1[c]>0){
                    freq1[c]--;
                    freq2[c]++;
                }
            }
            freq1 = freq2;
        }
        vector<string> res;
        for(auto p:freq1){
            char c = p.first;
            while(freq1[c]>0){
                res.push_back(string(1,c));
                freq1[c] --;
            }
        }
        return res;
    }
};