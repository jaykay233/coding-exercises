class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len%2==1){
            return findKth(nums1,nums2,0,0,len/2 + 1);
        }
        return (findKth(nums1,nums2,0,0,len/2) + findKth(nums1,nums2,0,0,len/2+1))/2.0;
    }

    double findKth(vector<int>& nums1,vector<int>& nums2,int start1,int start2, int k){
        if(start1>=nums1.size()) return nums2[start2 + k -1];
        if(start2>=nums2.size()) return nums1[start1 + k -1];
        if(k==1) return min(nums1[start1], nums2[start2]);
        double value1 = start1 + k/2 - 1 >= nums1.size() ? INT_MAX : nums1[start1 + k/2 - 1];
        double value2 = start2 + k/2 - 1 >= nums2.size() ? INT_MAX : nums2[start2 + k/2 - 1];
        if(value1 >= value2) return findKth(nums1, nums2, start1, start2 + k/2, k - k/2);
        return findKth(nums1,nums2,start1 + k/2, start2 , k - k/2);
    }
};