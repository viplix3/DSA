// https://leetcode.com/problems/combination-sum-iv/

// Recursive solution: Gives TLE
class Solution {
private:
    int findNumberOfCombinations(vector<int>& nums, int currIdx, int targetSum) {
        if(currIdx >= nums.size())
            return 0;
        
        if(targetSum == 0)
            return 1;
        
        int pickCombinations = 0, dontPickCombinations = 0;
        
        // Pick and start from 0 index as (1, 1, 2) and (2, 1, 1) are counted as
        // 2 separate combinations
        if(nums[currIdx] <= targetSum)
            pickCombinations = findNumberOfCombinations(nums, 0, targetSum - nums[currIdx]);
        
        //Don't pick
        dontPickCombinations = findNumberOfCombinations(nums, currIdx + 1, targetSum);
        
        return pickCombinations + dontPickCombinations;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        int startingIdx = 0;
        
        return findNumberOfCombinations(nums, startingIdx, target);
    }
};


// Memoization
class Solution {
private:
    int findNumberOfCombinations(vector<int>& nums, int currIdx, int targetSum,
                                vector<int>& cache) {
        if(currIdx >= nums.size())
            return 0;
        
        if(targetSum == 0)
            return 1;
        
        if(cache[targetSum] != -1)
            return cache[targetSum];
        
        int pickCombinations = 0, dontPickCombinations = 0;
        
        // Pick and start from 0 index as (1, 1, 2) and (2, 1, 1) are counted as
        // 2 separate combinations
        if(nums[currIdx] <= targetSum)
            pickCombinations = findNumberOfCombinations(nums, 0,targetSum - nums[currIdx],
                                                       cache);
        
        //Don't pick
        dontPickCombinations = findNumberOfCombinations(nums, currIdx + 1, targetSum,
                                                        cache);
        
        return cache[targetSum] = pickCombinations + dontPickCombinations;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        int startingIdx = 0;
        vector<int> cache(target + 1, -1);
        
        return findNumberOfCombinations(nums, startingIdx, target, cache);
    }
};