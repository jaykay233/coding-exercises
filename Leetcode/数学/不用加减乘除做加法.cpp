class Solution{
public:  
    int add(int a,int b){
        unsigned int a_ = a;
        unsigned int b_ = b;
        while(b_){
            int tmp = (a_&b_)<<1;
            a_^=b_;
            b_=tmp;
        }
        return a_;
    }
};