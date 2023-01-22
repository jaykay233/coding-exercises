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
    ListNode* reverse(ListNode* a,ListNode* b)
    {
        ListNode* pre = b, *cur = a;
        while(cur!=b)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* a,*b;
        a = b = head;
        for(int i =0;i<k;i++){
            if(b==nullptr) return head;
            b = b->next;
        }
        ListNode* newHead = reverse(a,b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};