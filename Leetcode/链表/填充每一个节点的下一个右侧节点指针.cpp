class Solution {
public:
    void handle(Node* &last, Node* &p, Node* &nextstart){
        if(last)
            last->next = p;
        if(!nextstart)
            nextstart=p;
        last = p;
    }

    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node* start = root;
        while(start){
            Node* last = nullptr, *nextstart = nullptr;
            for(Node* p = start;p!=nullptr;p=p->next){
                if(p->left)
                    handle(last,p->left,nextstart);
                if(p->right)
                    handle(last,p->right,nextstart);
            }
            start =nextstart;
        }
        return root;
    }
};