// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// Binary seach based solution, but because of repeating elements, it is O(N)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int beginIdx = 0, endIdx = nums.size() - 1;
        
        while(beginIdx <= endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            
            if(nums[midIdx] == target)
                return true;
            
            // Ignoring the duplicates
            if(nums[beginIdx] == nums[midIdx]
                 && nums[midIdx] == nums[endIdx]) {
                beginIdx++;
                endIdx--;
            }
            
            // First half sorted
            else if(nums[beginIdx] <= nums[midIdx]) {
                if(nums[beginIdx] <= target && target < nums[midIdx])
                    endIdx = midIdx - 1;
                else
                    beginIdx = midIdx + 1;
            }
            else {
                if(nums[midIdx] < target && target <= nums[endIdx])
                    beginIdx = midIdx + 1;
                else
                    endIdx = midIdx - 1;
            }
        }
        
        return false;
    }
};

// Because binary search has a worst case time complexity of O(N), we can also do linear search
// Binary search has best base time complexity of O(logN) so it is still a better approach
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int currNum : nums)
            if(currNum == target)
                return true;
        return false;
    }
};