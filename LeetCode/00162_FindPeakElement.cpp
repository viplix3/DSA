// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int numElems = nums.size();
        
        if(numElems == 1)
            return 0;
        
        int beginIdx = 0, endIdx = nums.size() - 1, peakIdx = -1;
        
        while(beginIdx <= endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            
            if( ((midIdx == 0 && nums[midIdx] > nums[midIdx + 1])
                    || (midIdx != 0 && nums[midIdx - 1] < nums[midIdx]))
                && ((midIdx == numElems - 1 && nums[midIdx - 1] < nums[midIdx])
                    || (midIdx != numElems - 1 && nums[midIdx] > nums[midIdx + 1])))
                return midIdx;
            
            // If we have a descreasing sequence from beginIdx to midIdx
            // i.e. nums[midIdx - 1] > nums[midIdx], we are sure to find a peak if we
            // search in this descreasing sequence
            if(midIdx != 0 && nums[midIdx - 1] > nums[midIdx])
                endIdx = midIdx - 1;
            else
                beginIdx = midIdx + 1;
        }
        
        return peakIdx;
    }
};