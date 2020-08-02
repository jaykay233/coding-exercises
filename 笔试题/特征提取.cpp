#include <bits/stdc++.h>
using namespace std;
int M;
unordered_map<string,int> m;

int main(){
    cin>>M;
    int ans = 0;
    for(int i =1;i<=M;i++){
        int n;
        cin>>n;
        if(n==0) {
            for(auto p:m){
                ans = max(ans,p.second);
            }
            m.clear();
            continue;
        }
        for(int i =1;i<=n;i++){
            int a,b;
            cin>>a>>b;
            string s = to_string(a)+" "+to_string(b);
            m[s]++;
        }
    }
    for(auto p:m){
        ans = max(ans,p.second);
    }
    
    cout<<ans<<endl;
    return 0;
}