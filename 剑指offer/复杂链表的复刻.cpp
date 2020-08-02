/**
 * Definition for singly-linked list with a random pointer.
 */
struct ListNode {
    int val;
    ListNode *next, *random;
    ListNode(int x) : val(x), next(NULL), random(NULL) {}
};


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void print(ListNode* t){
        while(t){
            cout<<t->val<<" ";
            t = t->next;
        }
        cout<<endl;
        return;
    }

    ListNode *copyRandomList(ListNode *head) {
        if(!head) return NULL;
        ListNode* head2 = head;
        while(head){
            ListNode* node = new ListNode(head->val);
            node->next = head->next;
            head->next = node;
            head = head->next->next;
        }
        
        
        head = head2;
        while(head){
            if(head->random) head->next->random = head->random->next;
            head = head->next->next;
        }
        
        // print(head2);
        
        
        head = head2;
        ListNode* newhead = head->next;
        ListNode* node2 = newhead;
        while(head){
            ListNode* temp = head->next->next;
            head->next = newhead->next;
            if(temp) newhead->next = temp->next;
            head = head->next;
            newhead = newhead->next;
        }
        return node2;
        
    }
};
