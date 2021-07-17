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