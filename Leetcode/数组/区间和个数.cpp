#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int countRangeSum(vector<int>& nums,int lower,int upper){
        long s = 0;
        vector<long> sums{0};
        for(auto& v:nums){
            s+=v;
            sums.push_back(s);
        }
        return countRangeSumInterval();
    }

    int countRangeSumInterval(vector<long>& sums,int left,int right,int lower,int upper){
        if(left==right) return 0;
        else{
            int mid = (left+right)/2;
            int n1 = countRangeSumInterval(sums,left,mid,lower,upper);
            int n2 = countRangeSumInterval(sums,mid+1,right,lower,upper);
            int ret = n1 + n2;
            int i = left;
            int l = mid + 1;
            int r  = mid + 1;
            while(i<=mid){
                while(l<=right && sums[l]-sums[i]<lower) l++;
                while(r<=right && sums[r] - sums[i]<=upper) r++;
                ret+=(r-l);
                i++;
            }
            vector<int> sorted(right-left+1);
            int p1=left,p2=mid+1;
            int p =0;
            while(p1<=mid || p2<=right){
                if(p1>mid)
                    sorted[p++] = sums[p2++];
                else if(p2>right)
                    sorted[p++] = sums[p1++];
                else{
                    if(sums[p1]<sums[p2])
                        sorted[p++] = sums[p1++];
                    else 
                        sorted[p++] = sums[p2++];
                }
            }
            for(int i=0;i<sorted.size();i++){
                sums[left+i] = sorted[i];
            }
            return ret;
        }
        return 0;
    }
};

//方法2

struct SegNode{
    int lo,hi,add;
    SegNode* lchild,*rchild;
    SegNode(int left,int right):lo(left),add(0),lchild(nullptr),rchild(nullptr) {}
};

class Solution2{
public: 
    SegNode* build(int left,int right){
        SegNode* node = new SegNode(left,right);
        if(left==right) return node;
        int mid = left + right>>1;
        node->lchild = build(left,mid);
        node->rchild = build(mid+1,right);
        return node;
    }

    void insert(SegNode* root,int val){
        root->add++;
        if(root->lo == root->hi) return;
        int mid = (root->lo + root->hi)/2;
        if(val<=mid) insert(root->lchild,val);
        else insert(root->rchild,val);
    }

    int count(SegNode* root,int left,int right){
        if(left>root->hi || right<root->lo) return 0;
        if(left<=root->lo && root->hi <=right) return root->add;
        return count(root->lchild,left,right) + count(root->rchild,left,right);
    }

    int countRangeSum(vector<int>& nums,int lower,int upper){
        long long sum = 0;
        vector<long long> preSum={0};
        for(int v:nums){
            sum+=v;
            preSum.push_back(sum);
        }

        set<long long> allNumbers;
        for(long long x:preSum){
            allNumbers.insert(x);
            allNumbers.insert(x-lower);
            allNumbers.insert(x-upper);
        }

        unordered_map<long long,int> values;
        int idx=0;
        for(long long x:allNumbers){
            values[x]=idx;
            idx++;
        }
        SegNode* root = build(0,values.size()-1);
        int ret= 0;
        for(long long x:preSum){
            int left = values[x-upper],right =values[x-lower];
            ret += count(root,left,right);
            insert(root,values[x]);
        }
        return ret;
    }
};

//方法3

class BIT{
private:
    vector<int> tree;
    int n;
public: 
    BIT(int _n){
        n = _n;
        tree =vector<int>(_n+1);
    }

    static constexpr int lowbit(int x){
        return x & (-x);
    }

    void update(int x,int d){
        while(x<=n){
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x) const{
        int ans = 0;
        while(x){
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution{
public: 
    int countRangeSum(vector<int>& nums,int lower,int upper){
        long long sum = 0;
        vector<long long> preSum={0};
        for(int v:nums){
            sum+=v;
            preSum.push_back(sum);
        }
        
        set<long long> allNumbers;
        for (long long x: preSum) {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }

        unordered_map<long long,int> values;
        int idx= 0 ;
        for (long long x: allNumbers) {
            values[x] = idx;
            idx++;
        }

        int ret =0 ;
        BIT bit(values.size());
        for(int i =0;i<preSum.size();i++){
            int left = values[preSum[i]-upper], right = values[preSum[i]-lower];
            ret += bit.query(right+1) - bit.query(left);
        }
        return ret;
    }
};