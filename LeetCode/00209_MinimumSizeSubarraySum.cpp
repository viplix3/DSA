// https://leetcode.com/problems/minimum-size-subarray-sum/

// Sliding window but with sharp edges
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int numSize = nums.size();
        int windowInitIdx = 0, windowEndIdx = 0, currWindowSum = 0;
        int minWindowSize = numSize + 1;
        
        while(windowEndIdx < numSize) {
            currWindowSum += nums[windowEndIdx];
            
            while(windowInitIdx <= windowEndIdx && currWindowSum > target) {
                minWindowSize = min(windowEndIdx - windowInitIdx + 1, minWindowSize);
                currWindowSum -= nums[windowInitIdx];
                windowInitIdx++;
            }
            
            if(currWindowSum == target)
                minWindowSize = min(windowEndIdx - windowInitIdx + 1, minWindowSize);
            
            windowEndIdx++;
        }
        
        return (minWindowSize == numSize + 1) ? 0 : minWindowSize;
    }
};