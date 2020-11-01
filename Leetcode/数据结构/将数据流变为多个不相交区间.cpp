#include <bits/stdc++.h>
using namespace std;

//set暴力
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    set<int> ans;
    SummaryRanges() {

    }
    
    void addNum(int val) {
        ans.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int left = *ans.begin();
        int right = *ans.begin();
        for(auto it=ans.begin();it!=ans.end();it++){
            if(*it>right+1){
                res.push_back({left,right});
                left=*it;
            }
            right=*it;
        }
        res.push_back({left,right});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */


//二分+树状数组
int maxn=10000;
int a[10000];
class SummaryRanges2 {
public:
    /** Initialize your data structure here. */
    set<int> s;
    SummaryRanges2() {
        memset(a,0,sizeof(a));
    }
    void addNum(int val) {
        if(s.count(val+1))
            return;
        for(int i=val+1;i<maxn;i+=i&-i){
            a[i]+=1;
        }
        s.insert(val+1);
    }
    int getr(int start){  //确定左边界找到最大的合法右边界
        int l=start,r=maxn,mid,ret;
        int init=0;
        for(int i=start-1;i>=1;i-=i&-i)
            init+=a[i];
        while(l<=r){
            mid=l+r>>1;
            int cnt=0;
            for(int i=mid;i>=1;i-=i&-i)
                cnt+=a[i];
            if(cnt-init==mid-start+1){
                ret=mid;
                l=mid+1;
            }else
                r=mid-1;
        }
        return ret;
    }
    int getl(int start){    //找到大于等于start的最小出现过的数字，没有则返回-1
        int l=start,r=maxn-1,mid,ret=-1;
        int init=0;
        for(int i=start-1;i>=1;i-=i&-i)
            init+=a[i];
        while(l<=r){
            mid=l+r>>1;
            int cnt=0;
            for(int i=mid;i>=1;i-=i&-i)
                cnt+=a[i];
            if(cnt-init>=1){
                ret=mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        return ret;
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        int start=1;
        while(start<maxn){
            int l=getl(start);
            if(l==-1)
                break;
            int r=getr(l);
            ret.push_back({l-1,r-1});
            start=r+1;
        }
        return ret;
    }
};
