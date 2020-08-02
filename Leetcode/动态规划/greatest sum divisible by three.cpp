#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int one=0;
        int two=0;
        int three=0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i]+one;
            int b=nums[i]+two;
            int c=nums[i]+three;
            if(a%3==0){
                if(a>three){
                    three=a;
                }
            }else if(a%3==1){
                if(a>one){
                    one=a;
                }
            }else if(a%3==2){
                if(a>two){
                    two=a;
                }
            }
            if(b%3==0){
                if(b>three){
                    three=b;
                }
            }else if(b%3==1){
                if(b>one){
                    one=b;
                }
            }else if(b%3==2){
                if(b>two){
                    two=b;
                }
            }
            if(c%3==0){
                if(c>three){
                    three=c;
                }
            }else if(c%3==1){
                if(c>one){
                    one=c;
                }
            }else if(c%3==2){
                if(c>two){
                    two=c;
                }
            }
            //cout<<one<<" "<<two<<" "<<three<<endl;
        }
        return three;
    }
};