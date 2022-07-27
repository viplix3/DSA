// https://leetcode.com/problems/first-missing-positive/

// Move nums[i] to i-th position
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numElems = nums.size();
        
        for(int i = 0; i < numElems; i++) {
            // Move nums[i] to nums[i]-th index
            // if nums[i] is 2, it would be moved to 2nd index
            while(0 < nums[i] && nums[i] < numElems && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        for(int i = 0; i < numElems; i++)
            if(nums[i] != i + 1)
                return i + 1;
        
        return numElems + 1;
    }
};

// Use array elements as index, mark negative once visisted
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int positiveIdx = 0, numElems = nums.size();
        
        // Push all the negative elements to the beginning
        for(int i = 0; i < numElems; i++)
            if(nums[i] <= 0) {
                swap(nums[i], nums[positiveIdx]);
                positiveIdx++;
            }
        
        for(long long i = positiveIdx; i < numElems; i++) {
            long long accessIdx = static_cast<long long>(abs(nums[i])) - 1 + positiveIdx;
            // -1 everywhere as 0 we are considering only positive missing
            // elements (exclusive of 0)
            if(accessIdx < numElems // If number is valid
               && nums[accessIdx] > 0) // Not already visited
                nums[accessIdx] = -nums[accessIdx]; // Mark element as visited
        }
        
        
        // The first non-negative index is the first missing positive
        for(int i = positiveIdx; i < numElems; i++)
            if(nums[i] > 0)
                return (i + 1) - positiveIdx;
        
        // If no non-negative number was found, nums contains elements ranging
        // from 1 to N
        return (numElems + 1) - positiveIdx;
    }
};