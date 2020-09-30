#include <bits/stdc++.h>
using namespace std;

class Solution{
public:   
    int minArray(vector<int>& numbers){
        int l = 0, r = numbers.size()-1;
        while(l<r){
            int m = l + r >> 1;
            if(numbers[m] < numbers[r]) r = m;
            else if(numbers[m] > numbers[r]) l = m + 1;
            else r --;
        }
        return numbers[l];
    }
};