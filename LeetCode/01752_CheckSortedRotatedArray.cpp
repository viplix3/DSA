// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// From leetcode discuss
class Solution {
public:
    bool check(vector<int>& nums) {
        int numSortedViolation = 0, numElems = nums.size();
        
        for(int i = 0; i < numElems - 1; i++) {
            if(nums[i] > nums[i+1])
                numSortedViolation += 1;
        }
        
        if(nums[numElems - 1] > nums[0])
            numSortedViolation += 1;
        
        return (numSortedViolation <= 1);
    }
};