#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin>>t;
    int n,p;
    vector<int> cand;
    for(int i =1;i<=t;i++){
        cin>>n>>p;
        cand.clear();
        for(int i =0;i<n;i++){
            int a;
            cin>>a;
            cand.push_back(a);
        }
        sort(cand.begin(),cand.end());
        int min_num = INT_MAX;
        vector<int> sums(cand.size()+1);
        for(int i =1;i<=cand.size();i++){
            sums[i] = sums[i-1] + cand[i-1];
            if(i>=p) min_num = min(min_num,cand[i-1]* p -(sums[i] - sums[i-p]));
        }
        printf("Case #%d: %d\n",i,min_num);
    }
    return 0;
}