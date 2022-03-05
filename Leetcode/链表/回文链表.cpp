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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode* firstHalf = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalf->next);

        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while(result && p2!=nullptr){
            if(p1->val!=p2->val)
                result = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        firstHalf->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* endOfFirstHalf(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};