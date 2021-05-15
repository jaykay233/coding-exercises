//AC自动机的精髓在于失配指针
#include <bits/stdc++.h>
using namespace std;

struct node{
    node* fail;
    node* child[26];
    int val;
    node(){
        this->fail = nullptr;
        memset(child,0,sizeof child);
        val = 0;
    }
};

node* Root= new node();
node* Q[100];
void BuildFailPoint(){
    int Qh =0,Qt=1;
    Q[1] = new node();
    while(Qh<Qt){
        node *now = Q[++Qh];
        for(int i =0;i<26;i++){
            if(now->child[i]!=nullptr){
                if(now==Root) now->child[i]->fail = Root;
                else{
                    node* p = now->fail;
                    while(p!=nullptr){
                        if(p->child[i]!=nullptr){
                            now->child[i]->fail = p->child[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p==nullptr) now->child[i]->fail = Root;
                }
                Q[++Qt] = now->child[i];
            }
        }  
    }
}