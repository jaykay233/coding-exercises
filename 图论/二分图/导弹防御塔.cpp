#include <bits/stdc++.h>
using namespace std;
int n,m,t2,v;
double t1;
const int N = 56,M = 2506;
const double eps = 1e-8;
pair<int,int> a[N],b[N];
pair<int,double> c[M];
vector<int> e[N];
int st[M];
int t;
int match[M];

double getdistance(pair<int,int> a,pair<int,int> b){
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return sqrt(dx*dx+dy*dy);
}

bool dfs(int i){
    for(int j:e[i]){
        if(!st[j]){
            st[j] = true;
            if(!match[j] || dfs(match[j])){
                match[j] = i;
                return true;
            }
        }
    }
    return false;
}

bool build(double mid){
    memset(match, 0, sizeof(match));
	for (int i = 1; i <= m; i++) {
		e[i].clear();
		for (int j = 1; j <= t; j++)
			if (c[j].second + getdistance(a[i], b[c[j].first]) / v <= mid)
				e[i].push_back(j);
	}
	for (int i = 1; i <= m; i++) {
		memset(st, 0, sizeof(st));
		if (!dfs(i)) return 0;
	}
	return 1;
}

int main(){
    cin>>n>>m>>t1>>t2>>v;
    t = n*m;
    t1/=60;
    for(int i =1;i<=m;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    for(int i=1;i<=n;i++){
        scanf("%d %d",&b[i].first,&b[i].second);
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int k = (i-1)*n+j;
            c[k].first = j;
            c[k].second = (i-1)*(t1+t2)+t1;
        }
    }

    double l = t1,r = 100000;
    while(l+eps<r){
        double mid = (r+l)/2;
        if(build(mid)) r = mid;
        else l = mid;
    }
    printf("%.6f\n",l);

    return 0;
}