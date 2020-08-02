#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> AS,BS;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            int x;
            cin>>x;
            if((i+j)%2) AS[x]++;
            else BS[x]++;
        }
    }

    vector<pair<int,int>> A,B;
    for(auto item:AS) A.push_back({item.second,item.first});
    for(auto item:BS) B.push_back({item.second,item.first});

    sort(A.begin(),A.end());reverse(A.begin(),A.end());
    sort(B.begin(),B.end());reverse(B.begin(),B.end());

    int res=0;
    for(int i =0;i<2 && i<A.size();i++){
        for(int j =0;j<2 && j<B.size();j++){
            if(A[i].second == B[j].second) res = max(res,max(A[i].first,B[j].first));
            else res = max(res,A[i].first + B[j].first);
        }
    }
    if(A.empty()) res = B[0].first;
    if(B.empty()) res = A[0].first;
    cout<<n*m-res<<endl;
    return 0;
}