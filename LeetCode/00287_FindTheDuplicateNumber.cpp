// https://leetcode.com/problems/find-the-duplicate-number/

// Floyd's algo, O(N), doesn't modify the array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int numElems = nums.size();
        int slowPtr = nums[0], fastPtr = nums[0];
        
        do {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        }
        while(slowPtr != fastPtr);
        
        slowPtr = nums[0];
        while(slowPtr != fastPtr) {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }
        
        return fastPtr;
    }
};

// Find occurrence count of each element: O(N), modifies the array
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