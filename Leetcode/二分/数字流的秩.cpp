class RankNode{
public:
    int data =0 ;
    int leftSize = 1;
    RankNode* left = nullptr;
    RankNode* right = nullptr;
    RankNode(int data_):data(data_){}

    void insert(int x){
        if(x==data)
            leftSize++;
        else if(x<data){
            if(left!=nullptr) left->insert(x);
            else left = new RankNode(x);
            leftSize ++;
        }else if(x>data){
            if(right!=nullptr) right->insert(x);
            else right = new RankNode(x);
        }
    }

    int getRank(int x){
        if(x==data) return leftSize;
        else if(x<data){
            if(left==nullptr) return 0;
            else return left->getRank(x);
        }
        else if(x>data){
            int rightRank = (right==nullptr)?0:right->getRank(x);
            return leftSize + rightRank;
        }
        return -1;
    }
};

class StreamRank {
public: 
    RankNode* root = nullptr;
    StreamRank() {

    }
    
    void track(int x) {
        if(root==nullptr)
            root = new RankNode(x);
        else
            root->insert(x);
    }
    
    int getRankOfNumber(int x) {
        if(root==nullptr)
            return 0;
        return root->getRank(x);
    }
};


/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */