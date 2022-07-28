// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Double binary search
class Solution {
private:
    int findFirstOccurrenceIndex(const vector<int>& nums, int target) {
        int beginIdx = 0, endIdx = nums.size() - 1;
        
        while(beginIdx <= endIdx) {
            int midIdx = (beginIdx + endIdx) / 2;
            
            if(nums[midIdx] > target)
                endIdx = midIdx - 1;
            else if(nums[midIdx] < target)
                beginIdx = midIdx + 1;
            else {
                if(midIdx == 0 || nums[midIdx - 1] != nums[midIdx])
                    return midIdx;
                else
                    endIdx = midIdx - 1;
            }
        }
        
        return -1;
    }
    
    int findLastOccurrenceIndex(const vector<int>& nums, int target) {
        int beginIdx = 0, endIdx = nums.size() - 1, numElems = nums.size() - 1;
        
        while(beginIdx <= endIdx) {
            int midIdx = (beginIdx + endIdx) / 2;
            
            if(nums[midIdx] > target)
                endIdx = midIdx - 1;
            else if(nums[midIdx] < target)
                beginIdx = midIdx + 1;
            else {
                if(midIdx == numElems || nums[midIdx + 1] != nums[midIdx])
                    return midIdx;
                else
                    beginIdx = midIdx + 1;
            }
        }
        
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccIdx = findFirstOccurrenceIndex(nums, target);
        
        if(firstOccIdx == -1)
            return {-1, -1};
            
        int lastOccIdx = findLastOccurrenceIndex(nums, target);
        
        return {firstOccIdx, lastOccIdx};
    }
};