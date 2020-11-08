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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> prefixSum;
        ListNode* dummy = new ListNode(0), *p = dummy;
        dummy->next = head;
        
        prefixSum[0] = p;
        int cur = 0, tempCur = 0;
        while (p = p->next) {
            cur += p->val;
            if (prefixSum.find(cur) != prefixSum.end()) {
                ListNode* temp = prefixSum[cur]->next;
                prefixSum[cur]->next = p->next;
                tempCur = cur;
                while (temp != p) {
                    tempCur += temp->val;
                    prefixSum.erase(tempCur);
                    temp = temp->next;
                }
                
            } else {
                prefixSum[cur] = p;
            }
        }
        
        return dummy->next;
    }
};
