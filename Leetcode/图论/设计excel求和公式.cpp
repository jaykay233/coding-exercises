#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    vector<node*> c;//我sum了谁
    vector<node*> f;//谁sum了我
    node(int _val=0):val(_val){};
};
node* A[30][30];
class Excel {
public:
    int m,n;
    Excel(int H, char W) {
        m=H,n=W-'A'+1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                A[i][j]=new node();
    }
    
    void set(int r, char c, int v) {
        int i=r-1,j=c-'A';
        clear(A[i][j]);
        update(A[i][j],v);
    }
    
    int get(int r, char c) {
        int i=r-1,j=c-'A';
        return A[i][j]->val;
    }    
    int sum(int r, char c, vector<string> strs) {
        int ii=r-1,jj=c-'A';
        clear(A[ii][jj]);
        int ret=0;
        for(string s:strs){
            vector<int> anchor=translate(s);
            for(int i=anchor[0];i<=anchor[2];i++){
                for(int j=anchor[1];j<=anchor[3];j++){
                    A[ii][jj]->c.push_back(A[i][j]);
                    A[i][j]->f.push_back(A[ii][jj]);
                    ret+=A[i][j]->val;
                }
            }
        }
        update(A[ii][jj],ret);
        return ret;
    }
    vector<int> translate(string s){
        vector<int> ret;
        for(int i=0;i<s.size();i++){
            if(s[i]==':'){
                auto a=helper(s.substr(0,i));
                ret.push_back(a.first);
                ret.push_back(a.second);
                a=helper(s.substr(i+1));
                ret.push_back(a.first);
                ret.push_back(a.second);
                return ret;
            }
        }
        auto a=helper(s);
        return {a.first,a.second,a.first,a.second};
    }
    pair<int,int> helper(string s){
        pair<int,int> ret;
        ret.second=s[0]-'A';
        ret.first=stoi(s.substr(1))-1;
        return ret;
    }
    void clear(node *cur){
        for(auto c:cur->c){
            auto it = c->f.begin();
            while(*it!=cur)
                it++;
            c->f.erase(it);
        }
        cur->c.clear();
    }
    void update(node *t,int v){
        int ori = t->val;
        queue<node *> q;
        q.push(t);
        while(!q.empty()){
            node *cur =q.front();
            q.pop();
            cur->val+=v-ori;
            for(auto f:cur->f)
                q.push(f);
        }
    }
};
