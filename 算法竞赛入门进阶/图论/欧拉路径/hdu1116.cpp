#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[30];
bool vis[30];
int tree[30];
int in[30];
int out[30];

void init(){
    for(int i =0;i<30;i++)
        tree[i] = i;
}

int find(int x){
    return tree[x]==x?x:tree[x]=find(tree[x]);
}

int merge(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x!=y) tree[x]=y;
    return;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        init();
        memset(num,0,sizeof num);
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        memset(vis,false,sizeof vis);
        int n;
        cin>>n;
        for(int i =0;i<n;i++){
            string str;
            cin>>str;
            int a = str[0] - 'a';
            int b = str.back() - 'a';
            num[a] ++;
            num[b] ++;
            out[a] ++;
            in[b]++;
            merge(a,b);
            vis[a]=vis[b]=true;
        }
        int cnt =0 ;
        for(int i =0;i<26;i++){
            if(vis[i] && tree[i]==i){
                cnt++;
            }
        }
        if(cnt>1) cout<<"The door cannot be opened."<<endl;
        else{
            int a=0,b=0,c=0;
            for(int i =0;i<26;i++){
                if(vis[i] && in[i]!=out[i]){
                    if(in[i]==out[i]+1)
                        a++;
                    else if(in[i]==out[i]-1){
                        b++;
                    }
                    else c++;
                }
            }
            if(c) cout<<"The door cannot be opened."<<endl;
            else{
                if((a==1&&b==1)||(!a&&!b)) {
                    cout<<"Ordering is possible."<<endl;
                }
                else cout<<"The door cannot be opened."<<endl;
            }
        }
    }
    return 0;
}