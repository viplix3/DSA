// https://leetcode.com/problems/maximum-average-subarray-i/

// Simple sliding window
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int numElems = nums.size();
        int windowEndIdx = k;
        
        double currWindowSum = 0.0, maxWindowSum = 0.0;
        
        for(int i = 0; i < k; i++)
            currWindowSum += nums[i];
        
        maxWindowSum = currWindowSum;
        while(windowEndIdx < numElems) {
            currWindowSum += (nums[windowEndIdx] - nums[windowEndIdx - k]);
            maxWindowSum = max(currWindowSum, maxWindowSum);
            windowEndIdx++;
        }
        
        return maxWindowSum / k;
    }
};