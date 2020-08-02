#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a = nums[0];
        int b = nums[0];
        do{
            a = nums[a];
            b = nums[nums[b]];
        }while(a!=b);
        
        int ptr1 = nums[0];
        int ptr2 = a;
        while(ptr1!=ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};

int main(){
    return 0;
}