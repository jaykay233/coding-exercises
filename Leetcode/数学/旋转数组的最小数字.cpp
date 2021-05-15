#include <bits/stdc++.h>
using namespace std;

class Solution{
public:   
    int minArray(vector<int>& numbers){
        int i =0,j = numbers.size()-1;
        while(i<j){
            int mid = i + j >> 1;
            if(numbers[mid] > numbers[j])
                i = mid + 1;
            else if(numbers[mid] < numbers[j])
                j = mid;
            else{
                j --;
            }
        }
        return numbers[i];
    }
};