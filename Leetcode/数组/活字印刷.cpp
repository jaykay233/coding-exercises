#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans;
    vector<bool> visited;
    int numTilePossibilities(string tiles) {
        int size = tiles.size();
        visited.assign(size,false);
        sort(tiles.begin(),tiles.end());
        backtrace(tiles,0);
        return ans;
    }

    void backtrace(string& tiles,int idx){
        if(idx == tiles.size()) return;
        for(int i =0;i<tiles.size();i++){
            if(visited[i] == true || i>0 && tiles[i] == tiles[i-1] && !visited[i-1]) continue;
            ans++;
            visited[i] = true;
            backtrace(tiles,idx+1);
            visited[i] = false;
        }
    }
};