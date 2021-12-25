//dfs序+树状数组
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
const int N = 500005;
struct Edge{ //邻接表——数组实现 (链式前向星)
    int to,next;
}edge[N];
 
int head[N],tot,d[N];
int in[N],out[N];  //in[i]:dfs第一次进入顶点i的时间戳，in[i]为dfs离开该节点的时间戳 
bool have[N];
int cnt;
 
void init(){
    tot = 0;
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(d,0,sizeof(d));
}
 
void addEdge(int u,int v,int &k){
    edge[k].to = v;
	edge[k].next = head[u];  //edge[k].next存储的是编号为i的边的（同样以u为起始点的）前一条边的编号 
	head[u] = k++;  //最后一条以u为起始点的边的编号 
}
 
void dfs(int u){  //dfs序 
    in[u] = ++cnt;
    for(int k=head[u];k!=-1;k=edge[k].next){
        dfs(edge[k].to);
    }
    out[u] = cnt;
}
 
int lowbit(int x){
    return x&(-x);
}
 
int sum(int x){
    int res = 0;
    while(x){
    	res+=d[x];
    	x-=lowbit(x);
	}
    return res;
}
 
void update(int x,int v){
	while(x<=cnt){
		d[x]+=v;
		x+=lowbit(x);
	}
}
 
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=0;i<n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v,tot);
        }
        dfs(1);
        /*for(int i=1;i<=n;i++){
            printf("%d %d\n",in[i],out[i]);
        }*/
        for(int i=1;i<=n;i++){
            have[i] = 1;
            update(in[i],1);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            char op;
            int x;
            scanf(" %c%d",&op,&x);  /*注意字符读入时，前面加上空格，这样可避免回车符的读入  
									当然字符也可以以字符串的形式读入，取第一个字符，这样前面就无需加空格了*/ 
            //cout<<"op="<<op<<"x="<<endl;
            if(op=='Q'){
                printf("%d\n",sum(out[x])-sum(in[x]-1));  //[in[x],out[x]]
            }else{
                if(have[x]) update(in[x],-1);
                else update(in[x],1);
                have[x] ^= 1;   //have[x] = !have[x];
            }
        }
    }
    return 0;
}