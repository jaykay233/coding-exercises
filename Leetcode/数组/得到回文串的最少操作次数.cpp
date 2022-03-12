//https://leetcode-cn.com/problems/minimum-number-of-moves-to-make-palindrome/solution/tan-xin-zheng-ming-geng-da-shu-ju-fan-we-h57i/
//贪心算法，每次交换最外边出现的字母不劣。因此贪心解法成立。
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n =s.size();
        int ans = 0;
        for(int i =0,j=n-1;i<j;i++){
            int find = 0;
            for(int k =j;k>i;k--){
                if(s[k] == s[i]){
                    for(;k<j;k++) swap(s[k],s[k+1]),ans++;
                    j--;
                    find = 1;
                    break;
                }
            }
            if(find == 0){
                ans += n/2 - i;
            }
        }
        return ans;
    }
};