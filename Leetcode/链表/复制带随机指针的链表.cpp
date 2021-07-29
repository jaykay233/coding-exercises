/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        for(Node* node = head; node!=nullptr; node=node->next->next){
            Node* node_new = new Node(node->val);
            node_new->next = node->next;
            node->next = node_new;
        }
        for(Node* node = head;node!=nullptr;node=node->next->next){
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for(Node* node=head;node!=nullptr;node=node->next){
            Node* node_new = node->next;
            node->next = node->next->next;
            node_new->next = (node_new->next) ? node_new->next->next : nullptr;
        }
        return headNew;
    }
};