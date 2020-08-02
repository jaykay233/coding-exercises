#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,int> memo;
    int kSimilarity(string A, string B) {
        return dfs(A,B,0);
    }
    
    int dfs(string cur,string B,int i){
        if(cur==B) return 0;
        if(memo.count(cur)) return memo[cur];
        int result = 0x3f3f3f3f;
        while(i<B.size() && cur[i]==B[i]) i++; //这句话很重要..使得记录的状态不受i的影响,同时省下状态记忆的维度
        for(int j = i+1;j<B.size();j++){
            if(cur[j]==B[i]){
                swap(cur[j],cur[i]);
                int next = dfs(cur,B,i+1);
                result = min(result,next+1);
                swap(cur[j],cur[i]);
            }
        }
        return memo[cur] = result;
    }
    
};