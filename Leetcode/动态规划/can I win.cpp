#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public: 
    bool canIWin(int maxChoosableInteger, int desiredTotal){
        if(maxChoosableInteger>=desiredTotal) return true;
        if(maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal) return false;
        unordered_map<int,bool> m;
        return canWin(maxChoosableInteger,desiredTotal,0,m);
    }

    bool canWin(int length,int total,int used, unordered_map<int,bool>& m){
        if(m.count(used)) return m[used];
        for(int i =0;i<length;i++){
            int cur = 1<<i;
            if((cur & used)==0){
                if(total<=i+1 || !canWin(length,total-(i+1),used|cur, m)){
                    return m[used] = true;
                }
            }
        }
        return m[used]=false;
    }
};


