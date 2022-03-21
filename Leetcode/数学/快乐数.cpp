//快慢指针
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        
        return slow == 1;
    }
    
    int bitSquareSum(int n){
        vector<int> digits;
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        int sum = 0;
        for(int d:digits){
            sum += d*d;
        }
        return sum;
    }
};