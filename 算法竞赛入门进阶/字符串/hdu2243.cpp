//hdu2243 -> poj2778
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 32;

int ch[maxn][26];
int f[maxn];
bool danger[maxn];
int sz;
void init(){
    sz = 1;
    memset(ch[0],0,sizeof ch[0]);
    memset(f,0,sizeof f);
    memset(danger,0,sizeof danger);
}

int idx(char c){
    return c - 'a';
}

void insert(char* s){
    int u =0,n=strlen(s);
    for(int i =0;i<n;i++){
        int c = idx(s[i]);
        if(!ch[u][c]){
            memset(ch[sz],0,sizeof ch[sz]);
            danger[sz] = false;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    danger[u] = true;
}

void getFail(){
    queue<int> q;
    while(!q.empty()) q.pop();
    f[0] = 0;
    for(int c =0;c<26;c++){
        int u = ch[0][c];
        if(u) {f[u]=0;q.push(u);}
    }
    while(!q.empty()){
        int r = q.front();q.pop();
        for(int c=0;c<26; c++){
            int u = ch[r][c];
            if(!u) {ch[r][c]=ch[f[r]][c];continue;}
            q.push(u);
            int v = f[r];
            while(v && !ch[v][c]) v = f[v];
            f[u] = ch[v][c];
            danger[u] |= danger[ch[v][c]];
        }
    }
}

ull mat[maxn*2][maxn*2];
ull A[maxn][maxn];
void build(){
    memset(A,0,sizeof A);
    for(int i =0;i<sz;i++){
        if(!danger[i]){
            for(int j=0;j<26;j++){
                int u = ch[i][j];
                if(!danger[u]) A[i][u]++;
            }
        }
    }
    memset(mat,0,sizeof mat);
    for(int i =0;i<sz;i++){
        for(int j =0;j<sz;j++){
            mat[i][j] = A[i][j];
        }
    }
    for(int i =0;i<sz;i++)
        mat[i+sz][i]=mat[i+sz][i+sz] = 1;
}

ull ans[maxn*2][maxn*2];

void pow_mod(int y) {
	ull tmp[maxn*2][maxn*2];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<sz*2;i++)
		ans[i][i]=1;
	for(;y;y>>=1) {
		if(y&1) {
			memset(tmp,0,sizeof(tmp));
			for(int i=0;i<sz*2;i++)
				for(int j=0;j<sz*2;j++)
					for(int k=0;k<sz*2;k++)
						tmp[i][j]=((ans[i][k]*mat[k][j])+tmp[i][j]);
			memcpy(ans,tmp,sizeof(tmp));
		}
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<sz*2;i++)
			for(int j=0;j<sz*2;j++)
				for(int k=0;k<sz*2;k++)
					tmp[i][j]=((mat[i][k]*mat[k][j])+tmp[i][j]);
		memcpy(mat,tmp,sizeof(tmp));
	}
}

ull tot[2][2];
ull mat2[2][2]={
    {26,0},
    {1,1}
};
void pow_mod_sum(int y) {
	ull tmp[2][2];
	mat2[0][0]=26;
	mat2[0][1]=0;
	mat2[1][0]=1;
	mat2[1][1]=1;
	memset(tot,0,sizeof(tot));
	for(int i=0;i<2;i++)
		tot[i][i]=1;
	for(;y;y>>=1) {
		if(y&1) {
			memset(tmp,0,sizeof(tmp));
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					for(int k=0;k<2;k++)
						tmp[i][j]=((tot[i][k]*mat2[k][j])+tmp[i][j]);
			memcpy(tot,tmp,sizeof(tmp));
		}
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					tmp[i][j]=((mat2[i][k]*mat2[k][j])+tmp[i][j]);
		memcpy(mat2,tmp,sizeof(tmp));
	}
}

char s[15];
ull seq[maxn][maxn*2];
ull ans2[maxn][maxn*2];
int main() {
    int n,l;
	while(~scanf("%d%d",&n,&l)) {
        init();
        for(int i=0;i<n;i++) {
            scanf("%s",s);
            insert(s);
        }
        getFail();
        build();
        pow_mod(l);
        memset(seq,0,sizeof(seq));
        memset(ans2,0,sizeof(ans2));
        for(int i=0;i<sz;i++) {
            for(int j=0;j<sz;j++) {
                seq[i][j+sz]=A[i][j];
            }
        }
        for(int i=0;i<sz;i++) {
            for(int j=0;j<2*sz;j++) {
                for(int k=0;k<2*sz;k++) {
                    ans2[i][j]=seq[i][k]*ans[k][j]+ans2[i][j];
                }
            }
        }
        ull a=0;
        for(int i=0;i<sz;i++) {
            a=(ans2[0][i]+a);
        }
        pow_mod_sum(l);
        ull sum=tot[1][0]*26;
        printf("%I64u\n",sum-a);
	}
}