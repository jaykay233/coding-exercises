#include <bits/stdc++.h>
using namespace std;

// reject sampling
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

//题目大致含义是凑成通过rand7()凑成1-40之内的数字再平摊到1-10，所以拒绝大于40的数字。

class Solution {
public:
    int rand10() {
        int row, col ,idx;
        do{
            row = rand7();
            col = rand7();
            idx = (row-1)*7+col;
        }while(idx>40);
        return 1+(idx-1)%10;
    }
};