class UnionFind{
public:
    vector<int> parent;
    int count;
    int getCount(){
        return count;
    }
    UnionFind(int n){
        this->count = n;
        this->parent = vector<int>(n);
        for(int i =0;i<n;i++){
            this->parent[i] = i;
        }
    }

    int find(int x){
        while(x!=parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void _union(int x,int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) 
            return;
        parent[rootx] = rooty;
        count--;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int len = row.size();
        int N = len/2;
        UnionFind unionfind(N);
        for(int i =0;i<len;i+=2){
            unionfind._union(row[i]/2,row[i+1]/2);
        }
        return N - unionfind.getCount();
    }


};

