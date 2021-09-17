class Node{
public:  
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node():val(0),left(nullptr),right(nullptr),next(nullptr) {}
    Node(int _val):val(_val),left(nullptr),right(nullptr),next(nullptr){}
    Node(int _val, Node* _left, Node* _right, Node* _next):val(_val),left(_left),right(_right),next(_next){}
};
class Solution{
public:  
    Node* connect(Node* root){
        if(root==nullptr) return root;
        Node* leftmost = root;
        while(leftmost->left){
            Node* head = leftmost;
            while(head){
                head->left->next = head->right;
                if(head->next){
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftmost = leftmost->right;
        }
        return root;
    }
};