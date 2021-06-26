/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution 
{
public:
    int getIndex(ArrayReader &reader) 
    {
        int n = reader.length();
        int L = 0;          //实指
        int R = n - 1;      //实指
        while (L < R)
        {
            int mid = (L + R) >> 1;
            //----------- 奇数个 L=0 [0 1 2] mid=3 [3 4 5 6] R=6
            if ((R - L) % 2 == 0)
            {
                //-- 比较[0 1 2] 和 [4 5 6]
                int check = reader.compareSub(L, mid - 1, mid + 1, R);
                //-- 左边大，在左
                if (check == 1)
                    R = mid - 1;            //左半R界为2
                //-- 右边大，在右
                else if (check == -1)
                    L = mid + 1;            //右半L界为4
                //-- 左右一样大，就是mid
                else
                    return mid;
            }
            //----------- 偶数个 L=0 [0 1 2] mid=2 [3 4 5] R=5
            else
            {
                //-- 比较[0 1 2] 和 [3 4 5]
                int check = reader.compareSub(L, mid, mid + 1, R);
                //-- 左边大，在左
                if (check == 1)
                    R = mid;                //左半R界为2
                //-- 右边大，在右
                else if (check == -1)
                    L = mid + 1;            //右半L界为3
                //-- 左右一样大，不存在
                else
                    return -1;
            }
        }

        return L;
    }
};
