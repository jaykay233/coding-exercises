#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <stack>
#include <set>
using namespace std;
typedef long long ll;
const int N=3e6+6;
int n,m;
//离线处理结构体
struct node{
    int type;
    string s;
    int pos;
}p[100010];
//AC自动机
namespace ac{
    int tr[N][26],tot;
    int val[N],fail[N],last[N];
    //初始化
    void init(){
        for(int i=0;i<=tot;i++){
            fail[i]=0;val[i]=0;last[i]=0;
            for(int j=0;j<26;j++){
                tr[i][j]=0;
            }
        }
        tot=0;
    }
    //建立tire树
    int insert(string s){
        int u=0;
        for(int i=0;s[i];i++){
            if(!tr[u][s[i]-'a'])tr[u][s[i]-'a']=++tot;
            u=tr[u][s[i]-'a'];
        }
        val[u]++;
        return u;//返回该字符串的节点下标
    }
    //建立字典图,也就是getfail
    void build(){
        queue<int >q;
        //初始化队列
        for(int i=0;i<26;i++){
            if(tr[0][i]){
                fail[tr[0][i]]=0;q.push(tr[0][i]);last[tr[0][i]]=0;
            }
        }
        //按bfs序列计算失配函数fail和后缀链接last
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(tr[u][i])
                fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
                else {tr[u][i]=tr[fail[u]][i];continue;}
                last[tr[u][i]]=val[fail[tr[u][i]]]?fail[tr[u][i]]:last[fail[tr[u][i]]];
            }
        }
    }
    //计算以节点t结尾的所有字符串(有着相同后缀的)个数和
    int cal(int t){
        int res=0;
        while(t){
            res+=val[t];
            t=last[t];
        }
        return res;
    }
    //模式匹配
    int query(string t){
        int u=0,res=0;
        for(int i=0;t[i];i++){
            int pt=t[i]-'a';
            while(u&&!tr[u][pt])u=fail[u];//沿着失配边走，知道可以匹配
            u=tr[u][pt];
            if(val[u]){//是模式串的结尾节点
                res+=cal(u);
            }
            else if(last[u]){//不是模式串的结尾节点就用last[u]找到u的结尾节点(有相同后缀)
                res+=cal(last[u]);
            }
        }
        return res;
    }
}
string s;
int ans[100010];
int main()
{
    int t;
    cin>>t;
    //scanf("%d",&t);
    while(t--){
        ac::init();
        cin>>n>>m;
        //scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            cin>>s;
            //scanf("%s",s);
            ac::insert(s);
        }
       // ac::build();
        int num=0;
        int type;
        while(m--){
            cin>>type>>s;
            if(type==1){
                p[++num].type=type;
                p[num].pos=ac::insert(s);//记录下该字符串的节点下标，以备后续抹掉
            }
            else {
                p[++num].type=2;
                p[num].s=s;
            }
        }
        ac::build();//建图:得到失配函数
        //倒叙查询
        for(int i=num;i>0;i--){
            if(p[i].type==2){
               ans[i]=ac::query(p[i].s);//模式匹配
            }
            else {
                ac::val[p[i].pos]--;//抹掉该字符串(val是个很重要的值)
            }
        }
        for(int i=1;i<=num;i++){
            if(p[i].type==2)cout<<ans[i]<<endl;
        }
    }
    getchar();
    getchar();
    return 0;
}