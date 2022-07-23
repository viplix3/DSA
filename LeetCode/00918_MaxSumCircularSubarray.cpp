// https://leetcode.com/problems/maximum-sum-circular-subarray/

// Kadane's single pass solution
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int numElems = nums.size();
        int currMax = nums[0], currMin = nums[0], arrSum = nums[0];
        int maxSubarraySum = currMax, minSubarraySum = currMin;
        
        for(int i = 1; i < numElems; i++) {
            currMax = max(currMax + nums[i], nums[i]);
            currMin = min(currMin + nums[i], nums[i]);
            
            maxSubarraySum = max(currMax, maxSubarraySum);
            minSubarraySum = min(currMin, minSubarraySum);
            arrSum += nums[i];
        }
        
        // All the entried are negative
        if(maxSubarraySum < 0)
            return maxSubarraySum;
        
        int maxCircularSubarraySum = max(maxSubarraySum, arrSum - minSubarraySum);
        return maxCircularSubarraySum;
    }
};


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