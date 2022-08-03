// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Merge but without repeat check
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsIntersection;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int nums1Itr = 0, nums2Itr = 0;
        int numElems1 = nums1.size(), numElems2 = nums2.size();
        
        while(nums1Itr < numElems1 && nums2Itr < numElems2) {
            if(nums1[nums1Itr] == nums2[nums2Itr]) {
                numsIntersection.push_back(nums1[nums1Itr]);
                nums1Itr++;
                nums2Itr++;
            }
            else if(nums1[nums1Itr] < nums2[nums2Itr])
                nums1Itr++;
            else
                nums2Itr++;
        }
        
        return numsIntersection;
    }
};