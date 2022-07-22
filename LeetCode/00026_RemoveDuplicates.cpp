// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numElems = nums.size();
        int nonDuplicateIdx = 0;
        
        for(int i = 1; i < numElems; i++)
            if(nums[i] != nums[nonDuplicateIdx]) {
                nums[++nonDuplicateIdx] = nums[i];
            }
        
        return nonDuplicateIdx + 1;
    }
};