//https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/submissions/
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n==1) return 0;
        int k = (m-1)%n;
        return (lastRemaining(n-1,m) + k + 1)%n;
    }
};