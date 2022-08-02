// https://leetcode.com/problems/merge-sorted-array/

// Standard merge sort, O(M + N) with O(M) aux space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sortedNumsItr = 0;
        int nums1Itr = 0, nums2Itr = 0;
        
        vector<int> nums1Copy(nums1.begin(), nums1.begin() + m);
        
        while(nums1Itr < m && nums2Itr < n) {
            if(nums1Copy[nums1Itr] < nums2[nums2Itr]) {
                nums1[sortedNumsItr] = nums1Copy[nums1Itr];
                nums1Itr++;
            }
            else {
                nums1[sortedNumsItr] = nums2[nums2Itr];
                nums2Itr++;
            }
            
            sortedNumsItr++;
        }
        
        while(nums1Itr < m) {
            nums1[sortedNumsItr] = nums1Copy[nums1Itr];
            nums1Itr++;
            sortedNumsItr++;
        }
        
        while(nums2Itr < n) {
            nums1[sortedNumsItr] = nums2[nums2Itr];
            nums2Itr++;
            sortedNumsItr++;
        }
    }
};