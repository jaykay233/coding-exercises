#include <bits/stdc++.h>
//统计入度-出度
using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> g(N+1,0);
        for(auto v:trust){
            g[v[0]] --;
            g[v[1]] ++;
        }
        for(int i =1;i<=N;i++){
            if(g[i]==N-1) return i;
        }
        return -1;
    }
};

//类似题目 find the celebrity
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution2 {
public:
    int findCelebrity(int n) {
        int res = 0;
        for(int i =0;i<n;i++){
            if(knows(res,i)) res = i;
        }
        for(int i =0;i<res;i++){
            if(knows(res,i) || !knows(i,res)) return -1;
        }
        for(int i =res+1;i<n;i++){
            if(!knows(i,res)) return -1;
        }
        return res;
    }
};