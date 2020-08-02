#include <cstdio>
#include <algorithm>
using namespace std;
struct P{
	int num,s,w;
};
int n,r,q;
P a[200002],b[200002],ans[200002];
bool pcmp(const P& a,const P& b) {
	return (a.s==b.s)?(a.num<b.num):(a.s>b.s); 
}
void solve() { 
	int ai=1,bi=1;
	for (int i=1;i<=n*2;i+=2) {
		if (ans[i].w>ans[i+1].w) { 
			ans[i].s++;
			a[ai++]=ans[i];
			b[bi++]=ans[i+1];
		}
		else { 
			ans[i+1].s++;
			a[ai++]=ans[i+1];
			b[bi++]=ans[i];
		}
	}

	int i=1,j=1,k=1;
	while (i<ai && j<bi) {
		if (pcmp(a[i],b[j])) {
			ans[k++]=a[i++];
		}
		else {
			ans[k++]=b[j++];
		}
	}
	while (i<ai) ans[k++]=a[i++];
	while (j<bi) ans[k++]=b[j++];
}
int main() {
	scanf("%d%d%d",&n,&r,&q);
	for (int i=1;i<=n*2;i++) {
		scanf("%d",&ans[i].s);
		ans[i].num=i;
	}
	for (int i=1;i<=n*2;i++) {
		scanf("%d",&ans[i].w);
	}
	sort(ans+1,ans+1+2*n,pcmp);
	for (int i=1;i<=r;i++) {
		solve();
	}
	printf("%d\n",ans[q].num);
	return 0;
}