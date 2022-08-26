// https://leetcode.com/problems/subarray-product-less-than-k/

// Sliding window
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // This solutio needs modifications if nums can have 0 as elements
        if(k == 0)
            return 0;
        
        int numElems = nums.size();
        int numSubarrays = 0;
        int windowBegin = 0, windowEnd = 0, windowProduct = 1;
        
        // for all the windows of variable sizes
        while(windowEnd < numElems) {
            windowProduct *= nums[windowEnd];
            
            while(windowBegin <= windowEnd && windowProduct >= k) {
                windowProduct /= nums[windowBegin];
                windowBegin++;
            }
            
            numSubarrays += (windowEnd - windowBegin + 1);
            windowEnd++;
        }
        
        return numSubarrays;
    }
};