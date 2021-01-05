/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* p = new PolyNode(-1,0,nullptr);
        PolyNode* dummyNode = p;
        while(poly1 && poly2){
            if(poly1->power>poly2->power){
                p->next = poly1;
                poly1 = poly1->next;
            }
            else if(poly1->power < poly2->power){
                p->next = poly2;
                poly2 = poly2->next;
            }else{
                int cf1 = poly1->coefficient;
                int cf2 = poly2->coefficient;
                if(cf1+cf2==0) {
                    poly1=poly1->next;
                    poly2=poly2->next;
                    continue;
                }
                p->next = new PolyNode(cf1+cf2,poly1->power);
                poly1=poly1->next;
                poly2=poly2->next;
            }
            p = p->next;
        }
        if(poly1){
            p->next = poly1;
        }else{
            p->next = poly2;
        }
        return dummyNode->next;
    }
};