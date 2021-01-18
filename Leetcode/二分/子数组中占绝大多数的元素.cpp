//超时
#include <bits/stdc++.h>
using namespace std;
//https://leetcode-cn.com/problems/online-majority-element-in-subarray/solution/shu-tao-shu-by-elvis-10/
//树状数组套线段树
struct SegNode{
    int sum;
    SegNode* left;
    SegNode* right;
    SegNode():sum(0),left(nullptr),right(nullptr){}
};

struct TreeArray{
    int MAXN;
    vector<SegNode*> arr;
    TreeArray(int size){
        MAXN = size;
        arr=vector<SegNode*>(size);
        for(int i =0;i<size;i++) arr[i]=new SegNode();
    }    
};




class MajorityChecker {
public:
    TreeArray* outTree;
    const int MAXN=100000;
    int lowbit(int x){
        return x&(-x);
    }

    void insertTree(int p,int val){
        while(val<MAXN){
            outTree->arr[val]->sum += 1;
            insertNode(outTree->arr[val],0,MAXN,p);
            val += lowbit(val);
        }
        return;
    }

    void insertNode(SegNode* root,int start,int end,int p){
        if(start>=end) return;
        else{
            int mid = start + end >> 1;
            if(p<=mid) {
                if(root->left==nullptr) root->left = new SegNode();
                root->left->sum += 1;
                insertNode(root->left,start,mid,p);
            }else{
                if(root->right==nullptr) root->right = new SegNode();
                root->right->sum +=1;
                insertNode(root->right,mid+1,end,p);
            }
        }
    }


    MajorityChecker(vector<int>& arr) {
        outTree = new TreeArray(MAXN);
        for(int i =0;i<arr.size();i++){
            insertTree(i,arr[i]);
        }
    }
    
    int queryTree(int mid,int left,int right){
        int res = 0;
        while(mid>0){
            int cnt = queryNode(outTree->arr[mid],0,MAXN,left,right);
            res+=cnt;
            mid -= lowbit(mid);
        }
        return res;
    }

    int queryNode(SegNode* node,int start,int end, int left,int right){
        if(left>end || right<start) return 0;
        else if(start>=left && end<=right ) return node->sum;
        else{
            int mid = (start+end)>>1,res=0;
            if(node->left) res += queryNode(node->left,start,mid,left,right);
            if(node->right) res += queryNode(node->right,mid+1,end,left,right);
            return res;
        }
    }


    int query(int left, int right, int threshold) {
        int start =1,end = 20000;
        while(start<end){
            int mid = start + end >> 1,cnt =queryTree(mid,left,right);
            if(cnt<threshold) start = mid + 1;
            else end = mid;
        }
        int total = queryTree(start,left,right) - queryTree(start-1,left,right);
        if(total>=threshold) return start;
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */


//换种写法的树套树
const int MAXN=2e4+50;
const int MAXM=2e4;

struct BTree{ int ch[2], sum; }node[MAXN*100];
int root[MAXN], numn, PL, PR;

inline int lowbit(int x){ return x&-x; }

void init(){ 
    numn=0;
    memset(root, 0, sizeof(root));
}

void insertNode(int &x, int l, int r, int p){
    if (!x) { x=++numn; node[x].ch[0]=node[x].ch[1]=node[x].sum=0; }

    ++node[x].sum;

    if (l<r){
        int m=(l+r)/2;
        if (p<=m){
            insertNode(node[x].ch[0], l, m, p);
        }else insertNode(node[x].ch[1], m+1, r, p);
    }
}

void insertTree(int p, int v){
    for (int i=v; i<=MAXM; i+=lowbit(i)) 
        insertNode(root[i], PL, PR, p);
}

int queryNode(int x, int l, int r, int left, int right){
    if (!x) return 0;
    if (left<=l && r<=right) return node[x].sum;

    int m=(l+r)/2, ret=0;
    if (left<=m) ret+=queryNode(node[x].ch[0], l, m, left, right);
    if (m+1<=right) ret+=queryNode(node[x].ch[1], m+1, r, left, right);

    return ret;
}

int queryTree(int left, int right, int v){
    int ret=0;
    for (int i=v; i>0; i-=lowbit(i))
        ret+=queryNode(root[i], PL, PR, left, right);
    return ret;
}

class MajorityChecker {
public:
    MajorityChecker(vector<int>& a) {
        PL=0, PR=a.size()-1;
        init();
        for (int i=PL; i<=PR; i++) insertTree(i, a[i]);
    }
    
    int query(int left, int right, int threshold) {
        int ans=0, now=32768/2, k=threshold;
        while(now){
            if (now+ans>MAXM) { now/=2; continue; }
            int v=queryNode(root[ans+now], PL, PR, left, right);
            if (v<k) { k-=v; ans+=now; }
            now/=2;
        }
        
        int cnt=queryTree(left, right, ans+1) - queryTree(left, right, ans);
        return cnt>=threshold?ans+1:-1;
    }
};

