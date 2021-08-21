class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        int sum = 0;
        while(sum + 9 * pow(10,digit-1) * digit <= n){
            sum += 9 * pow(10, digit-1) * digit;
            digit ++;
        }
        cout<<digit<<endl;
        int diff = n - sum;
        cout<< diff << endl;
        int number = diff / digit;
        int pos = diff % digit;
        cout<<"number: "<<number<<" pos: "<<pos<<endl;
        int res = pow(10, digit-1) - 1 + number;
        if(pos == 0) return res % 10;
        string t = to_string(res + 1);
        return t[pos-1] - '0';
    }
};