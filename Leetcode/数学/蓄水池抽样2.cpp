#include <bits/stdc++.h>
using namespace std;

//1/n的蓄水池抽样

class Solution{
public:  
    ListNode* head;
    Solution(ListNode* head){
        this->head = head;
    }

    int getRandom(){
        int cnt =0 ;
        ListNode* node = head;
        ListNode* r = NULL;
        while(node){
            if(!cnt){
                r = node;
            }else{
                int p = rand()%cnt;;
                if(p<1)
                    r = node;
            }
            node = node->next;
        }
        return r->val;
    }
}