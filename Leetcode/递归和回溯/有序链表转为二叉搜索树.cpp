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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* getMedian(ListNode* l,ListNode* r){
        ListNode* slow = l;
        ListNode* fast = l;
        while(fast!=r && fast->next!=r){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        return slow;
    }

    TreeNode* build(ListNode* left,ListNode* right){
        if(left==right) return nullptr;
        ListNode* middle = getMedian(left,right);
        TreeNode* t = new TreeNode(middle->val);
        t->left = build(left,middle);
        t->right = build(middle->next,right);
        return t;
    }    

    TreeNode* sortedListToBST(ListNode* head) {
        return build(head,nullptr);
    }
};