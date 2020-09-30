class Solution {
public:

    int div(int a,int b){
        if(a<b) return 0;
        int ans = 1;
        int acc =b;
        while(a-acc>=acc){
            ans+=ans;
            acc+=acc;
        }
        return ans += div(a-acc,b);
    }
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        else if(divisor==1) return dividend;
        else if(divisor==-1) return dividend==INT_MIN?INT_MAX:-dividend;
        bool flag = (dividend>0 && divisor>0) || (dividend<0 && divisor<0);
        
        if(divisor==INT_MIN) return dividend==INT_MIN?1:0;
        int ans = 0;
        if(dividend== INT_MIN){ //处理a为特殊值的情况
            dividend = (flag)? dividend - divisor : dividend + divisor;
            ++ans;
        } 
        dividend = dividend>0?dividend:-dividend;
        divisor = divisor>0?divisor:-divisor;
        ans+=div(dividend,divisor);
        if(!flag) ans = -ans;
        return ans;
    }
};