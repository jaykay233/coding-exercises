#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string alphabetBoardPath(string target) {
        int r =0, c = 0;
        ostringstream os;
        for(const auto& ch: target){
            auto [nr, nc] = position(ch);
            int dr = nr - r, dc = nc - c;
            if(dr<0) os<<string(-dr,'U');
            if(dc<0) os<<string(-dc,'L');
            if(dr>0) os<<string(dr,'D');
            if(dc>0) os<<string(dc,'R');
            os<<"!";
            r = nr;
            c = nc;
        }
        return os.str();
    }

    pair<int,int> position(const char ch){
        const int index = tolower(ch) - 'a';
        return {index/5, index%5};
    }
};