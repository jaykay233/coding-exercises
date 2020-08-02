#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
int p[2*N];
int n,m;

struct crime{
    int val,a,b;
    bool operator<(const crime t) const{
        return val>t.val;
    }
};
vector<crime> crimes;

int find(int a){
    if(p[a]==a) return a;
    return p[a] = find(p[a]);
}

void debug(){
    for(int i =0;i<crimes.size();i++){
        cout<<crimes[i].val<<' ';
    }
    cout<<endl;
}


int main(){
    scanf("%d %d",&n,&m);
    for(int i =1;i<=2*N;i++) p[i] = i;
    for(int i =1;i<=m;i++){
        int val,a,b;
        cin>>a>>b>>val;
        crimes.push_back({val,a,b});
    }
    sort(crimes.begin(),crimes.end());
    debug();

    for(int i =0;i<crimes.size();i++){
        int id1 = crimes[i].a;
        int id2 = crimes[i].b;
        int anger =crimes[i].val;
        int fa = find(id1);
        int fb = find(id2);
        int fan = find(id1+N);
        int fbn = find(id2+N);
        if(fa==fb){
            cout<<anger<<endl;
            return 0;
        }else{    
            p[fa] = fbn;
            p[fb] = fan;
        }
    }
    cout<<0<<endl;

    return 0;
}