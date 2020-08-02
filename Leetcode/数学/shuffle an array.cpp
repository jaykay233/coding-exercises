// Fisher-Yates Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
class Solution{
public:
    vector<int> array;
    vector<int> original;
    Solution(vector<int>& nums){
        this->array = nums;
        this->original = nums;
    }
    vector<int> reset(){
        this->array = this->original;
        return this->array;
    }

    vector<int> shuffle(){
        for(int i =0;i<this->array.size();i++){
            int swapidx = rand()%(this->array.size() - i) + i;
            swap(this->array[swap_idx],this->array[i]);
        }
        return this->array;
    }
};