#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<iostream>
using namespace std;
const int maxn=1000+100;
 
struct Max_Match
{
    int n;
    vector<int> g[maxn];
    bool vis[maxn];
    int left[maxn];
 
    void init(int n)
    {
        this->n=n;
        for(int i=1;i<=n;i++) g[i].clear();
        memset(left,-1,sizeof(left));
    }
 
    bool match(int u)
    {
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!vis[v])
            {
                vis[v]=true;
                if(left[v]==-1 || match(left[v]))
                {
                    left[v]=u;
                    return true;
                }
            }
        }
        return false;
    }
 
    int solve()
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(match(i)) ++ans;
        }
        return ans;
    }
}MM;
 
struct Node
{
    string s;
    bool link(Node& rhs)//判断两个string是否只相差1位
    {
        int num = 0;
        for(int i=0;i<s.size(); i++)
            if(s[i]!=(rhs.s)[i]) ++num;
        return num==1;
    }
}node[maxn];
 
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M)==2 && N)
    {
        int num=0;
        set<string> st;//判重string
        for(int i=1;i<=M;i++)
        {
            string s;
            cin>>s;
            if(s.find("*")!=-1)
            {
                int pos=s.find("*");
                string s1(s),s2(s);
                s1[pos]='0';
                s2[pos]='1';
                if(st.find(s1) == st.end())//s1与已有string不重复
                {
                    st.insert(s1);
                    node[++num].s = s1;
                }
                if(st.find(s2) == st.end())//s2与已有string不重复
                {
                    st.insert(s2);
                    node[++num].s = s2;
                }
            }
            else
            {
                if(st.find(s) == st.end())
                {
                    st.insert(s);
                    node[++num].s = s;
                }
            }
        }
 
        MM.init(num);
        for(int i=1;i<=num;i++)
        for(int j=1;j<=num;j++)if(i!=j)
        if(node[i].link(node[j]))
            MM.g[i].push_back(j);
        printf("%d\n",num-MM.solve()/2);
    }
    return 0;
}