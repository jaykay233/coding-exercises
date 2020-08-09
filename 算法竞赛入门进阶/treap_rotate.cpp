#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct Node{
    int value;
    Node* son[2];
};

void rotate(Node* &o,int d){
    Node *k = o->son[d^1];
    o->son[d^1] = k->son[d];
    k->son[d] = o;
    o = k;
}


int main(){

    return 0;
}