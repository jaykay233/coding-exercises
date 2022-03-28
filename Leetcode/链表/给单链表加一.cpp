/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* node = reverseList(head);
        ListNode* tmp = node;
        node->val++;
        int carry = 0;
        ListNode* pr = nullptr;
        while(node){
            int val = node->val + carry;
            node->val = val%10;
            carry = val/10;
            pr = node;
            node = node->next;
        }
        if(carry)
            pr->next = new ListNode(carry);
        return reverseList(tmp);
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};