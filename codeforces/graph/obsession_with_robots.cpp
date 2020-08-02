#include <bits/stdc++.h>
using namespace std;
const int N = 202;

int main(){
    string s;
    cin>>s;
    int sx = 101,sy = 101;
    int g[N][N];
    memset(g,0,sizeof g);
    int prex,prey;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    bool ok = true;
    for(int i =0;i<s.size();i++){
        if(g[sx][sy]){
            ok = false;
            cout<<"BUG"<<endl;
            break;
        }
        g[sx][sy] = 1;
        prex = sx,prey = sy;
        if(s[i]=='R') sy++;
        else if(s[i]=='L') sy--;
        else if(s[i]=='U') sx--;
        else if(s[i]=='D') sx++;
        for(int j =0;j<4;j++){
            int x = sx + dirs[j][0];
            int y = sy + dirs[j][1];
            if(g[x][y] && (prex!=x || prey!=y)){
                ok = false;
                cout<<"BUG"<<endl;
                break;
            }
        }
        if(!ok) break;
    }
    if(ok) {cout<<"OK"<<endl;}

    return 0;
}