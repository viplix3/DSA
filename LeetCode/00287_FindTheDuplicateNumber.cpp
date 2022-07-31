// https://leetcode.com/problems/find-the-duplicate-number/

// Find occurrence count of each element: O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int numElems = nums.size();
        
        for(int i = 0; i < numElems; i++)
            nums[i]--;
        
        for(int i = 0; i < numElems; i++)
            nums[nums[i] % numElems] += numElems;
        
        for(int i = 0; i < numElems; i++)
            nums[i] /= numElems;
        
        for(int i = 0; i < numElems; i++)
            if(nums[i] > 1)
                return i+1;
        
        return -1;
    }
};