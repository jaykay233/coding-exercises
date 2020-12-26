#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public: 
    vector<ListNode*> splitListToParts(ListNode* root,int k){
        vector<ListNode*> linked(k,nullptr);
        ListNode* node = root;
        int length = 0;
        while(node){
            node = node->next;
            length++;
        }
        int avg=length/k;
        int remain = length%k;
        ListNode* tmp = root;
        for(int i=0;i<k;i++){
            linked[i] = tmp;
            for(int j=0;j<avg-1+(i<remain?1:0) && tmp!=nullptr;j++){
                tmp = tmp->next;
            }
            if(tmp==nullptr)
                break;
            ListNode* ne = tmp->next;
            tmp->next = nullptr;
            tmp = ne;
        }
    }
};