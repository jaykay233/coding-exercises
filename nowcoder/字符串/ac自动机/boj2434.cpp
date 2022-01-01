#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
#define N 100000

struct edge{
    int next,node;
};

int fail[N];

struct tree{
    int head[N+1], tot;
    edge e[N+1];
    reset(){tot=0;}
    void addedge(int x,int y){
        e[++tot].next = head[x];
        e[tot].node = y;
        head[x] = tot;
    }
}failTree, queryTree;

const int root = 1;
struct node{
    int f, son[26], fail;
}t[N+1];
//Trie tree
string s;
int m;

int main(){
    ios::with_sync_stdio(false);
    cin>>s;
    int len = s.size();
    int now = root;
    cin>>m;
    for(int x,y,i=0;i<m;i++){
        cin>>x>>y;
        queryTree.add(y,x);
    }
    for(int i =0;i<len;i++){
        if(s[i]=='P') strNode[++strs]=now;
        else if(s[i]=='B') now = t[now].f;
        else{
            if(t[now].son[s[i]-'a']) now = t[now].son[s[i]-'a'];
            else{
                int cur = now;
                t[now=t[now].son[s[i]-'a']=++tot].f = cur;
            }
        }
    }
    for(int i =0;i<26;i++){
        if(t[root].son[i]){
            fail[t[root].son[i]]=root; q.push(t[root].son[i]);
            failTree.addedge(root,t[root].son[i]);
        }
    }

    while(!q.empty()){
        for(int i =0;i<26;i++){
            int u = q.front();q.pop();
            if(t[k].son[i]){
                fail[t[k].son[i]] = t[fail[k]].son[i];
                failTree.addedge(fail)
                q.push(t[k].son[i]);
            }
        }
    }

}