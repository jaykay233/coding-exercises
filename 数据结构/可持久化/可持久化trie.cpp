#include <bits/stdc++.h>
using namespace std;
const int N = 600010;
int n,m;
int now;
int cnt =0 ;
int trie[N*24][2];
int latest[N];
int nums[N];
int root[N];

void insert(int pre,int& now,int root,int val,int k){
    if(!now) now = ++cnt;
    latest[now] = root;
    if(k<0) {return;}
    int c = (val>>k)&1;
    trie[now][c^1] = trie[pre][c^1];
    insert(trie[pre][c],trie[now][c],root,val,k-1);
}

int query(int now,int version,int val,int k){
    if(k<0) return latest[now];
    int c = (val>>k) & 1;
    if(latest[trie[now][c^1]]>=version) return query(trie[now][c^1],version,val,k-1);
    else return query(trie[now][c],version,val,k-1);
}

int main(){
    cin>>n>>m;
    int temp;
    int count =0;
    for(int i = 1;i<=n;i++){
        cin>>temp;
        count++;
        nums[count] = nums[count-1] ^ temp;
        insert(root[count-1],root[count],count,nums[count],25);
    }
    latest[0] = -1;
    char op[10];
    for(int i=1;i<=m;i++){
        scanf("%s",op);
        if(op[0]=='A'){
            int temp;
            cin>>temp;
            count++;
            nums[count] = nums[count-1] ^temp;
            insert(root[count-1],root[count],count,nums[count],25);
        }else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            int val = nums[count] ^ x;
            int p = query(root[r-1],l-1,val,25);
            cout<<(nums[p]^val)<<endl;
        }
    }

    return 0;
}