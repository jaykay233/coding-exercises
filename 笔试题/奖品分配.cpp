#include <bits/stdc++.h>
using namespace std;
vector<int> res;

int main(){
    int T;
    cin>>T;
    for(int i =1;i<=T;i++){
        int n;
        cin>>n;
        res.clear();
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            res.push_back(a);
        }
        vector<int> ans(res.size(),1);
        for(int i=0;i<res.size()*2;i++){
            if(res[i%n]>res[(i-1+n)%n]){
                ans[i%n] = max(ans[i%n],ans[(i-1+n)%n]+1);
            } 
        }

        for(int i = res.size()*2;i>=0;i--){
            if(res[i%n]>res[(i+1)%n]){
                ans[i%n] = max(ans[i%n],ans[(i+1)%n]+1);
            }
        }
        // for(int i =0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        cout<<accumulate(ans.begin(),ans.end(),0)<<endl;

    }
    return 0;
}