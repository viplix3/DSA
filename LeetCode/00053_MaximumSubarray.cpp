// https://leetcode.com/problems/maximum-subarray/

// Kadane's algo: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int numElems = nums.size();
        int currSum = nums[0], maxSum = currSum;
        
        for(int i = 1; i < numElems; i++) {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
};