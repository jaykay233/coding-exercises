/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode* headA = head;
        ListNode* headB = head->next;
        while(headB && headB->next){
            if(headA==nullptr || headB == nullptr) return false;
            if(headA == headB) return true;
            headA = headA->next;
            headB = headB->next->next;
        }
        return false;
    }
};


class SolutionV2 {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* first = head;
        ListNode* second = head->next;
        while(second && second->next){
            if(first==second) return true;
            first = first->next;
            second = second->next->next;
        }   
        return false;
    }
};