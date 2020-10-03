//单链表快排
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // int num = head->val;
        // ListNode* p = head;
        // ListNode* q = head->next;
        ListNode* end = head;
        while(end){
            end = end->next;
        }
        ListNode* tmp = head;
        quicksort(head,end);
        return tmp;
    }

    ListNode* partition(ListNode* start,ListNode* end){
        int num = start->val;
        ListNode* p = start;
        ListNode* q = start->next;
        while(q != end){
            if(q->val < num){
                p = p->next;
                swap(p->val,q->val);
            }
            q = q->next;
        }
        swap(p->val,start->val);
        return p;
    }

    void quicksort(ListNode* start,ListNode* end){
        if(start != end){
            ListNode* index = partition(start,end);
            quicksort(start,index);
            quicksort(index->next,end);
        }
    }
};