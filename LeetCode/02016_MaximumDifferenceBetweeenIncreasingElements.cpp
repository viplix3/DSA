// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int numElems = nums.size();
        int currMin = nums[0], maxDiff = 0;
        
        for(int i = 1; i < numElems; i++) {
            maxDiff = max(nums[i] - currMin, maxDiff);
            currMin = min(nums[i], currMin);
        }
        
        return (maxDiff == 0) ? -1 : maxDiff;
    }
};