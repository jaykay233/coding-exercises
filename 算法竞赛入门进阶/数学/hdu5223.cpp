#include <bits/stdc++.h>
using namespace std;
int N,Q;
struct node{
    int a,b,ymax;
}nodes[1004];

int s[1004];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cin>>N>>Q;
        for(int i=1;i<=N;i++)
            s[i] = 1;
        for(int i=1;i<=Q;i++){
            scanf("%d%d%d",&nodes[i].a,&nodes[i].b,&nodes[i].ymax);
            for(int j=nodes[i].a;j<=nodes[i].b;j++){
                int p = gcd(s[j],nodes[i].ymax);
                s[j] = s[j]/p*nodes[i].ymax;
            }
        }
        bool flag = true;
        for(int i=1;i<=Q;i++){
            int cur = s[nodes[i].a];
            for(int j=nodes[i].a+1;j<=nodes[i].b;j++)
                cur = gcd(cur,s[j]);
            if(cur!=nodes[i].ymax){
                flag = false;
                break;
            }
        }
        if(!flag)
            cout<<"Stupid BrotherK!"<<endl;
        else{
            int first = 0;
            for(int j=1;j<=N;j++){
                if(first++) cout<<" ";
                cout<<s[j];
            }
            cout<<endl;
        }
    }    
    return 0;
}