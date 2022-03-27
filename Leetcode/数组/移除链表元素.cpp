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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = new ListNode(-1);
        node->next = head;
        head = node;
        while(head && head->next){
            if(head->next->val == val){
                head->next = head->next->next;
            }
            else{
                head = head->next;
            }
        }
        return node->next;
    }
};