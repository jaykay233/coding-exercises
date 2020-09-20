//https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-by-lee/
class Solution{
public:  
    int lastRemaining(int n,int m){
        return f(n,m);
    }
    int f(int n,int m){
        if(n==1) return 0;
        int x = f(n-1,m);
        return (m+x)%n;
    }
};