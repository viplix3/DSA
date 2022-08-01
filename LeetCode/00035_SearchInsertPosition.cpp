// https://leetcode.com/problems/search-insert-position/

// Binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beginIdx = 0, endIdx = nums.size() - 1;
        
        while(beginIdx <= endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            
            if(nums[midIdx] == target)
                return midIdx;
            if(nums[midIdx] < target)
                beginIdx = midIdx + 1;
            else
                endIdx = midIdx - 1;
        }
        
        return beginIdx;
    }
};