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