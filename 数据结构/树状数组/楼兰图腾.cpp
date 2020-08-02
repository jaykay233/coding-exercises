#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 200010;
typedef long long LL;
int a[N];
int sb[N];
int sa[N];
int bb[N];
int ba[N];
int b[N];

void add(int x){
    while(x<=n){
        b[x]+=1;
        x += x&(-x);
    }
}

int get(int x){
    int res =0;
    while(x){
        res+=b[x];
        x-=x&(-x);
    }
    return res;
}

void print(){
    for(int i =1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
}



int main(){
    cin>>n;
    memset(b,0,sizeof b);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        int value = a[i];
        sb[i]= get(value);
        bb[i] = get(n) - (sb[i]);
        add(value);
    }

    
    memset(b,0,sizeof(b));
    for(int i =n;i;i--){
        int value = a[i];
        sa[i] = get(value);
        ba[i] = get(n) - (sa[i]);
        add(value);
    }
    
    LL up =0,down =0 ;
    for(int i=1;i<=n;i++){
        down+=(long long)bb[i]*ba[i];
        up+=(long long)sb[i]*sa[i];
    }
    
    cout<<down<<" "<<up<<endl;
    
    return 0;
}