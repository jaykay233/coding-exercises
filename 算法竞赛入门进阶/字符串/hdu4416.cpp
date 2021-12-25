//https://blog.csdn.net/aekijekzn484879763/article/details/101842368
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000008;
struct Suffix_Automation{
    int nt[N<<1][26], a[N<<1], fail[N<<1];
    int tot, last, root;
    int p,q,np,nq;
    int newnode(int len){
        for(int i =0;i<26;i++) nt[tot][i] = -1;
        fail[tot] = -1; a[tot] = len;
        return tot++;
    }
    void clear(){
        tot = last = 0;
        root = newnode(0);
    }

    void insert(int ch)
	{
		p = last; last = np = newnode(a[p] + 1);
		for (; ~p && nt[p][ch] == -1; p = fail[p]) nt[p][ch] = np;
		if (p == -1) fail[np] = root;
		else
		{
			q = nt[p][ch];
			if (a[p] + 1 == a[q]) fail[np] = q;
			else
			{
				nq = newnode(a[p] + 1);
				for (int i = 0; i < 26; ++i) nt[nq][i] = nt[q][i];
				fail[nq] = fail[q];
				fail[np] = fail[q] = nq;
				for (; ~p && nt[p][ch] == q; p = fail[p]) nt[p][ch] = nq;
			}
		}
	}
    long long solve()
	{
		long long ans = 0;
		for (int i = 1; i < tot; ++i) ans += a[i] - a[fail[i]];
		return ans;
	}
}sam;

int main(){
    cin.sync_with_stdio(0);
    int T; cin>>T;
    for(int cas=1;cas<=T;cas++){
        sam.clear();
        int n; cin>>n;
        string s;cin>>s;
        for(int i=1;i<=n;i++){
            string t; cin>>t;
            sam.last =0 ;
            for(int j =0, len=t.length();j<len;j++)
                sam.insert(t[j]-'a');
        }        
        long long ans1=sam.solve();
        sam.last = 0;
        for(int j =0,len=s.size();j<len;j++)
            sam.insert(s[j]-'a');
        long long ans2 =sam.solve();
        cout<<"Case " << cas << ": "<<ans2-ans1 << endl;
    }
    return 0;
}

