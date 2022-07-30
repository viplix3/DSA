// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int numElems1 = nums1.size(), numElems2 = nums2.size();
        
        if(numElems1 > numElems2)
            return findMedianSortedArrays(nums2, nums1);
        
        // Binary search to be done only in 1st array
        int beginIdx = 0, endIdx = numElems1;
        
        while(beginIdx <= endIdx) {
            int midIdx1 = (beginIdx + endIdx) / 2;
            int midIdx2 = (numElems1 + numElems2 + 1) / 2 - midIdx1;
            
            int maxLeftArr1 = (midIdx1 == 0) ? INT_MIN : nums1[midIdx1 - 1];
            int maxLeftArr2 = (midIdx2 == 0) ? INT_MIN : nums2[midIdx2 - 1];
            int maxLeft = max(maxLeftArr1, maxLeftArr2);
            
            int minRightArr1 = (midIdx1 == numElems1) ? INT_MAX : nums1[midIdx1];
            int minRightArr2 = (midIdx2 == numElems2) ? INT_MAX : nums2[midIdx2];
            int minRight = min(minRightArr1, minRightArr2);
            
            if(maxLeftArr1 <= minRightArr2 && maxLeftArr2 <= minRightArr1) {
                if((numElems1 + numElems2) % 2 == 0)
                    return static_cast<double>((maxLeft + minRight) / 2.0);
                else
                    return static_cast<double>(maxLeft);
            }
            if(maxLeftArr1 > minRightArr2)
                endIdx = midIdx1 - 1;
            else
                beginIdx = midIdx1 + 1;
        }
        
        return -1.0;
    }
};