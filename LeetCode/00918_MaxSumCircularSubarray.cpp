// https://leetcode.com/problems/maximum-sum-circular-subarray/

// Kadane's algo
// Find maxSubarraySum, minSubarraySum and totalArraySum
// maxCircularSubarraySum = totalArraySum - maxNegativeSubarraySum
// maxCircularSubarraySum = max(maxSubarraySum, totalArraySum - minSubarraySum);
class Solution {
private:
    int findMaxSubarraySum(const vector<int>& arr) {
        int numElems = arr.size();
        int currSum = arr[0], maxSum = currSum;
        
        if(numElems == 1)
            return currSum;
        
        for(int i = 1; i < numElems; i++) {
            currSum = max(currSum + arr[i], arr[i]);
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
    
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int numElems = nums.size();
        int maxSubarraySum = findMaxSubarraySum(nums);
        
        if(maxSubarraySum < 0) // All the array elements are negative and this is the best sum
            return maxSubarraySum;
        
        int arrSum = 0;
        for(int i = 0; i < numElems; i++) {
            arrSum += nums[i];
            nums[i] *= -1; // Inverse array polarity
        }
        
        // Because all the entried are negative of original, findMaxSubArraySum
        // would return minSubarraySum
        int minSubarraySum = findMaxSubarraySum(nums);
        int maxCircularSubarraySum = max(maxSubarraySum, arrSum + minSubarraySum);
        
        return maxCircularSubarraySum;
    }
};