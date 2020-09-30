pNode* partition(pNode* start,pNode* end){
    int num = start->val;
    pNode* p = start;
    pNode* q = start->next;
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


void quick_sort(pNode* start,pNode* end){
    if(start != end){
        pNode* index = partition(start,end);
        quick_sort(start,index);
        quick_sort(index->next,end);
    }
}