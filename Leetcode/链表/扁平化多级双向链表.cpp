#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Node* first = nullptr;
    Node* flatten(Node* head) {
        if(!head) return head;
        flat(head);
        return head;
    }

    void flat(Node* head){
        if(!head) return;
        if(first!=nullptr){
            first->next = head;
            head->prev = first;
        }
        first = head;
        Node* t = head->next;
        flat(head->child);
        head->child = nullptr;
        flat(t);
    }
};