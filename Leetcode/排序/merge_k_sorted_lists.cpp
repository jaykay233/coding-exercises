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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node = new ListNode(-1);
        ListNode* tmp = node;
        // cout<<"ok"<<endl;
        while(!lists.empty()){
            ListNode* nodemin = NULL;
            int minidx= 0 ;
            for(int i =0;i<lists.size();i++){
                auto list = lists[i];
                if(list==NULL) continue;
                if(nodemin==NULL){
                    nodemin = list;
                    minidx = i;
                }else if(nodemin && list &&  nodemin->val > list->val){
                    nodemin = list;
                    minidx = i;
                }
            }
            if(nodemin==NULL) break;
            node->next = nodemin;
            lists[minidx] = lists[minidx]->next;
            if(lists[minidx]==NULL)
                lists.erase(lists.begin()+minidx);
            node = node->next;
        }
        return tmp->next;
    }
};
