#include <bits/stdc++.h>
using namespace std;
int n;
int k;
const int N = 210;
int a[N][N];
int cnt[N];
int idx[N];

bool cmp(int a,int b){
    return cnt[a] < cnt[b];
}

int main(){
    cin>>n;
    cin>>k;
    for(int i =0;i<n;i++){
        for(int j =0;j<k;j++) scanf("%d",&a[i][j]);
        for(int j =0;j<k;j++){
            for(int t =j+1;t<k;t++){
                if(a[i][j]>a[i][t]) cnt[i]++;
            }
        }
        idx[i] = i;
    }
    sort(idx,idx+n,cmp);
    cout<<"[";
    for(int i =0;i<n;i++){
        cout<<"[";
        for(int j =0;j<k;j++){
            cout<<a[idx[i]][j];
            if(j!=k-1) cout<<", ";
        }
        cout<<"]";
        if(i!=n-1) cout<<", ";
    }
    
    cout<<"]";

    return 0;
}