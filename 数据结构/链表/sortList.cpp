#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

//单链表快排
class Solution {
public:
    
    void quicksort(ListNode* head,ListNode* end){
        if(head==NULL || head==end) return;
        ListNode* small = head;
        ListNode* p = head->next;
        while(p!=end){
            if(p->val<head->val){
                small = small->next;
                swap(small->val,p->val);
            }
            p = p->next;
        }
        swap(head->val,small->val);
        quicksort(head,small);
        quicksort(small->next,end);
    }
    
    ListNode* quicksortList(ListNode* head) {
        quicksort(head,NULL);
        return head;
    }

    ListNode* mergesortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout<<slow->val<<endl;
        ListNode* mid = slow;
        pre->next = NULL;
        ListNode* head2 = mergesortList(mid);
        ListNode* head1 = mergesortList(head);
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;
        while(head1 && head2){
            if(head1->val<head2->val){
                dummy->next = head1;
                head1 = head1->next;
            }else{
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
        }
        if(head1) dummy->next = head1;
        if(head2) dummy->next = head2;
        return node->next;
    }

};

int main(){
    return 0;
}