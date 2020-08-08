//题解链接：https://leetcode.com/problems/transform-to-chessboard/solution/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size();
        unordered_map<int,int> count;
        for(vector<int>& row:board){
            int code =0 ;
            for(int x:row)
                code = code * 2 + x;
            count[code] += 1;
        }
        cout<<count.size()<<endl;
        
        int k1 = analyze(count,N);

        if(k1==-1) return -1;
        
        count = unordered_map<int,int>();
        for(int c=0;c<N;c++){
            int code = 0;
            for(int r =0;r<N;r++)
                code = code * 2 + board[r][c];
            count[code] += 1;
        }
        int k2 = analyze(count,N);
        return k2>=0?k1+k2 : -1;
    }
    
    int bitcount(int N){
        int count = 0;
        while(N){
            N&=(N-1);
            count++;
        }
        return count;
    }
    
    int analyze(unordered_map<int,int> count,int N){
        if(count.size()!=2) return -1;
        vector<int> keys;
        for(auto P:count){
            keys.push_back(P.first);
        }
        
        int k1 = keys[0],k2= keys[1];
        // cout<<(count[k2]==N/2)<<endl;
        // cout<<(count[k1]==(N+1)/2)<<endl;
        if(!(count[k1]==N/2 && count[k2]==(N+1)/2) && !(count[k2]==N/2 && count[k1]==(N+1)/2)) return -1;
        
        if((k1^k2)!=(1<<N)-1) return -1;
        
        int Nones = (1<<N)-1;
        int ones = bitcount(k1 & Nones);
        int cand = INT_MAX;
        if(N%2==0 || ones * 2 < N)
            cand = min(cand, bitcount(k1 ^ 0xAAAAAAAA & Nones)/2);
        if(N%2==0 || ones * 2 > N)
            cand = min(cand, bitcount(k1 ^ 0x55555555 & Nones)/2);
        return cand;
    }
};
