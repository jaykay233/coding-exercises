#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(mid, piles, h) == true)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool check(int speed, vector<int> & piles, int h)
    {
        int cnt = 0;
        for (int p : piles)
            cnt += ceil((double)p / speed);
        return cnt <= h;
    }
};
