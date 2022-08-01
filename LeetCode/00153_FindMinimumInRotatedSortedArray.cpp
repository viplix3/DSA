// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Binary seach, simple solution
// When search for a target we do, endIdx = midIdx - 1 with while(begin <= endIdx)
// When we don't have a target we do, endIdx = midIdx with while(begin < endIdx)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int beginIdx = 0, endIdx = nums.size() - 1;
        int minElem = min(nums[beginIdx], nums[endIdx]);
        
        while(beginIdx < endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            
            // First half of the array is sorted
            if(nums[beginIdx] < nums[midIdx]) {
                minElem = min(nums[beginIdx], minElem);
                beginIdx = midIdx + 1;
            }
            else { // Second half of the array is sorted
                minElem = min(nums[midIdx], minElem);
                endIdx = midIdx;
            }
        }
        
        return minElem;
    }
};

// Binary search for rotated sorted array, janky solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int beginIdx = 0, endIdx = nums.size() - 1;
        int minElem = min(nums[beginIdx], nums[endIdx]);
        
        while(beginIdx <= endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            
            // First half of the array is sorted
            if(nums[beginIdx] < nums[midIdx]) {
                minElem = min(nums[beginIdx], minElem);
                beginIdx = midIdx + 1;
            }
            else { // Second half of the array is sorted
                if(midIdx != endIdx)
                    minElem = min(nums[midIdx + 1], minElem);
                
                minElem = min(nums[midIdx], minElem);
                endIdx = midIdx - 1;
            }
        }
        
        return minElem;
    }
};